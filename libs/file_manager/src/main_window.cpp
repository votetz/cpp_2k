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
    contextMenu.addAction("New File", this, &MainWindow::createNewFile);
    contextMenu.addAction("New Folder", this, &MainWindow::createNewFolder);

    if (index.isValid()) {
        contextMenu.addSeparator();
        contextMenu.addAction("Rename", this, &MainWindow::renameItem);
        contextMenu.addAction("Delete", this, &MainWindow::deleteItem);
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
        QString fullPath = dirPath + "/" + fileName;
        QFile file(fullPath);
        if (file.open(QIODevice::WriteOnly)) {
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Could not create file.");
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
        QDir dir(dirPath);
        if (!dir.mkdir(folderName)) {
            QMessageBox::warning(this, "Error", "Could not create folder.");
        }
    }
}

void MainWindow::renameItem() {
    if (!currentContextMenuIndex.isValid()) {
        return;
    }

    QModelIndex sourceIndex = proxyModel->mapToSource(currentContextMenuIndex);
    QString oldPath = fileSystemModel->filePath(sourceIndex);
    QFileInfo fileInfo(oldPath);

    bool ok;
    QString newName = QInputDialog::getText(this, "Rename", "Enter new name:", QLineEdit::Normal, fileInfo.fileName(), &ok);

    if (ok && !newName.isEmpty() && newName != fileInfo.fileName()) {
        QString newPath = fileInfo.absolutePath() + "/" + newName;
        if (!QFile::rename(oldPath, newPath)) {
            QMessageBox::warning(this, "Error", "Could not rename item.");
        }
    }
}

void MainWindow::deleteItem() {
    if (!currentContextMenuIndex.isValid()) {
        return;
    }

    QModelIndex sourceIndex = proxyModel->mapToSource(currentContextMenuIndex);
    QString filePath = fileSystemModel->filePath(sourceIndex);
    QFileInfo fileInfo(filePath);

    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Delete", "Are you sure you want to delete \"" + fileInfo.fileName() + "\"?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (fileInfo.isDir()) {
            QDir dir(filePath);
            if (!dir.removeRecursively()) {
                QMessageBox::warning(this, "Error", "Could not delete folder.");
            }
        } else {
            if (!QFile::remove(filePath)) {
                QMessageBox::warning(this, "Error", "Could not delete file.");
            }
        }
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
