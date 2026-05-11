#include "main_window.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QInputDialog>
#include <QFile>
#include <QDir>
#include <QPixmap>
#include <QDesktopServices>
#include <QUrl>
#include <QHeaderView>
#include <QLoggingCategory>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      treeView(new QTreeView(this)),
      fileSystemModel(new QFileSystemModel(this)),
      proxyModel(new QSortFilterProxyModel(this)),
      searchLineEdit(new QLineEdit(this)),
      textPreview(new QTextEdit(this)),
      imagePreview(new QLabel(this)),
      splitter(new QSplitter(Qt::Horizontal, this)),
      previewWidget(new QWidget(this)),
      currentContextMenuIndex() {

    QLoggingCategory::setFilterRules("qt.qpa.wayland.textinput=false");

    newFileAction = new QAction("New File", this);
    connect(newFileAction, &QAction::triggered, this, &MainWindow::createNewFile);

    newFolderAction = new QAction("New Folder", this);
    connect(newFolderAction, &QAction::triggered, this, &MainWindow::createNewFolder);

    copyAction = new QAction(tr("&Copy"), this);
    copyAction->setShortcut(QKeySequence::Copy);
    connect(copyAction, &QAction::triggered, this, &MainWindow::copyItem);
    this->addAction(copyAction);

    pasteAction = new QAction(tr("&Paste"), this);
    pasteAction->setShortcut(QKeySequence::Paste);
    connect(pasteAction, &QAction::triggered, this, &MainWindow::pasteItem);
    this->addAction(pasteAction);

    renameAction = new QAction("Rename", this);
    renameAction->setShortcut(QKeySequence(Qt::Key_F2));
    connect(renameAction, &QAction::triggered, this, &MainWindow::renameItem);
    this->addAction(renameAction);

    deleteAction = new QAction("Delete", this);
    deleteAction->setShortcut(QKeySequence::Delete);
    connect(deleteAction, &QAction::triggered, this, &MainWindow::deleteItem);
    this->addAction(deleteAction);

    m_file_executor = new FileExecutor(this);

    setupUi();
}

MainWindow::~MainWindow() = default;

void MainWindow::setupUi() {
    setWindowTitle("File Manager");
    resize(1200, 700);

    fileSystemModel->setRootPath("");
    fileSystemModel->setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);

    proxyModel->setSourceModel(fileSystemModel);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setRecursiveFilteringEnabled(true);

    treeView->setModel(proxyModel);
    treeView->setRootIndex(proxyModel->mapFromSource(fileSystemModel->index(QDir::homePath())));
    treeView->setContextMenuPolicy(Qt::CustomContextMenu);
    treeView->setSelectionMode(QAbstractItemView::SingleSelection);
    treeView->setSortingEnabled(true);
    treeView->header()->setSectionResizeMode(0, QHeaderView::Stretch);

    connect(treeView, &QTreeView::doubleClicked, this, &MainWindow::onTreeViewDoubleClicked);
    connect(treeView, &QTreeView::customContextMenuRequested, this, &MainWindow::onTreeViewCustomContextMenu);
    connect(treeView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &MainWindow::onSelectionChanged);

    searchLineEdit->setPlaceholderText("Search files...");
    connect(searchLineEdit, &QLineEdit::textChanged, this, &MainWindow::onSearchTextChanged);

    textPreview->setReadOnly(true);
    imagePreview->setAlignment(Qt::AlignCenter);
    imagePreview->setScaledContents(false);

    QVBoxLayout *previewLayout = new QVBoxLayout(previewWidget);
    previewLayout->addWidget(textPreview);
    previewLayout->addWidget(imagePreview);
    previewLayout->setContentsMargins(0, 0, 0, 0);
    textPreview->hide();
    imagePreview->hide();

    QWidget *leftWidget = new QWidget(this);
    QVBoxLayout *leftLayout = new QVBoxLayout(leftWidget);
    leftLayout->addWidget(searchLineEdit);
    leftLayout->addWidget(treeView);
    leftLayout->setContentsMargins(0, 0, 0, 0);

    splitter->addWidget(leftWidget);
    splitter->addWidget(previewWidget);
    splitter->setStretchFactor(0, 2);
    splitter->setStretchFactor(1, 1);

    setCentralWidget(splitter);
}

void MainWindow::onTreeViewDoubleClicked(const QModelIndex &index) {
    QModelIndex sourceIndex = proxyModel->mapToSource(index);
    QString filePath = fileSystemModel->filePath(sourceIndex);
    QFileInfo fileInfo(filePath);

    if (fileInfo.isFile()) {
        QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
    }
}

void MainWindow::onTreeViewCustomContextMenu(const QPoint &pos) {
    QModelIndex index = treeView->indexAt(pos);
    currentContextMenuIndex = index;

    QMenu contextMenu(this);

    contextMenu.addAction(newFileAction);
    contextMenu.addAction(newFolderAction);

    if (m_file_executor->has_copy_source()) {
        contextMenu.addAction(pasteAction);
    }

    if (index.isValid()) {
        contextMenu.addSeparator();

        contextMenu.addAction(copyAction);

        contextMenu.addAction(renameAction);
        contextMenu.addAction(deleteAction);
    }

    contextMenu.exec(treeView->viewport()->mapToGlobal(pos));
}
void MainWindow::onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected) {
    Q_UNUSED(deselected);

    if (selected.indexes().isEmpty()) {
        clearPreview();
        return;
    }

    QModelIndex proxyIndex = selected.indexes().first();
    QModelIndex sourceIndex = proxyModel->mapToSource(proxyIndex);
    QString filePath = fileSystemModel->filePath(sourceIndex);
    QFileInfo fileInfo(filePath);

    if (fileInfo.isFile()) {
        updatePreview(filePath);
    } else {
        clearPreview();
    }
}

void MainWindow::onSearchTextChanged(const QString &text) {
    proxyModel->setFilterWildcard(text.isEmpty() ? QString() : "*" + text + "*");
}

void MainWindow::createNewFile() {
    QModelIndex sourceIndex = currentContextMenuIndex.isValid()
                                  ? proxyModel->mapToSource(currentContextMenuIndex)
                                  : fileSystemModel->index(QDir::homePath());

    QString dirPath = fileSystemModel->isDir(sourceIndex)
                          ? fileSystemModel->filePath(sourceIndex)
                          : fileSystemModel->fileInfo(sourceIndex).absolutePath();

    bool ok;
    QString fileName = QInputDialog::getText(this, "New File", "Enter file name:", QLineEdit::Normal, "", &ok);

    if (ok && !fileName.isEmpty()) {
        QString error = m_file_executor->create_new_file(dirPath, fileName);
        if (!error.isEmpty()) {
            QMessageBox::warning(this, "Error", error);
        }
    }
}

void MainWindow::createNewFolder() {
    QModelIndex sourceIndex = currentContextMenuIndex.isValid()
                                  ? proxyModel->mapToSource(currentContextMenuIndex)
                                  : fileSystemModel->index(QDir::homePath());

    QString dirPath = fileSystemModel->isDir(sourceIndex)
                          ? fileSystemModel->filePath(sourceIndex)
                          : fileSystemModel->fileInfo(sourceIndex).absolutePath();

    bool ok;
    QString folderName = QInputDialog::getText(this, "New Folder", "Enter folder name:", QLineEdit::Normal, "", &ok);

    if (ok && !folderName.isEmpty()) {
        QString error = m_file_executor->create_new_folder(dirPath, folderName);
        if (!error.isEmpty()) {
            QMessageBox::warning(this, "Error", error);
        }
    }
}

void MainWindow::renameItem() {
    if (!currentContextMenuIndex.isValid()) {
        return;
    }

    QModelIndex sourceIndex = proxyModel->mapToSource(currentContextMenuIndex);
    QString oldPath = fileSystemModel->filePath(sourceIndex);

    bool ok;
    QString newName = QInputDialog::getText(this, "Rename", "Enter new name:", QLineEdit::Normal, QFileInfo(oldPath).fileName(), &ok);

    if (ok && !newName.isEmpty()) {
        QString error = m_file_executor->rename_item(oldPath, newName);
        if (!error.isEmpty()) {
            QMessageBox::warning(this, "Error", error);
        }
    }
}

void MainWindow::deleteItem() {
    if (!currentContextMenuIndex.isValid()) {
        return;
    }

    QModelIndex sourceIndex = proxyModel->mapToSource(currentContextMenuIndex);
    QString filePath = fileSystemModel->filePath(sourceIndex);

    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Delete", "Are you sure you want to delete \"" + QFileInfo(filePath).fileName() + "\"?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QString error = m_file_executor->delete_item(filePath);
        if (!error.isEmpty()) {
            QMessageBox::warning(this, "Error", error);
        }
    }
}

void MainWindow::copyItem() {
    if (!currentContextMenuIndex.isValid()) {
        return;
    }
    QModelIndex sourceIndex = proxyModel->mapToSource(currentContextMenuIndex);
    QString filePath = fileSystemModel->filePath(sourceIndex);
    m_file_executor->set_copy_source(filePath);
}

void MainWindow::pasteItem() {
    if (!currentContextMenuIndex.isValid()) {
        return;
    }
    QModelIndex sourceIndex = proxyModel->mapToSource(currentContextMenuIndex);
    QString targetDirPath = fileSystemModel->isDir(sourceIndex)
                                ? fileSystemModel->filePath(sourceIndex)
                                : fileSystemModel->fileInfo(sourceIndex).absolutePath();
    QString error = m_file_executor->paste(targetDirPath);
    if (!error.isEmpty()) {
        QMessageBox::warning(this, "Error", error);
    }
}

void MainWindow::updatePreview(const QString &filePath) {
    clearPreview();

    QFileInfo fileInfo(filePath);
    QString suffix = fileInfo.suffix().toLower();

    if (suffix == "txt" || suffix == "cpp" || suffix == "h" || suffix == "hpp" || 
        suffix == "c" || suffix == "cc" || suffix == "cxx") {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString content = in.readAll();
            textPreview->setPlainText(content);
            textPreview->show();
            file.close();
        }
    } else if (suffix == "png" || suffix == "jpg" || suffix == "jpeg" || 
               suffix == "bmp" || suffix == "gif") {
        QPixmap pixmap(filePath);
        if (!pixmap.isNull()) {
            QPixmap scaled = pixmap.scaled(previewWidget->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            imagePreview->setPixmap(scaled);
            imagePreview->show();
        }
    }
}


void MainWindow::clearPreview() {
    textPreview->clear();
    textPreview->hide();
    imagePreview->clear();
    imagePreview->hide();
}
