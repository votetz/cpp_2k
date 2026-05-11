#pragma once

#include <QMainWindow>
#include <QTreeView>
#include <QFileSystemModel>
#include <QSortFilterProxyModel>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QSplitter>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include "file_executor.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void onTreeViewDoubleClicked(const QModelIndex &index);
    void onTreeViewCustomContextMenu(const QPoint &pos);
    void onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void onSearchTextChanged(const QString &text);
    void createNewFile();
    void createNewFolder();
    void renameItem();
    void deleteItem();
    void copyItem();
    void pasteItem();

private:
    void setupUi();
    void updatePreview(const QString &filePath);
    void clearPreview();

    FileExecutor* m_file_executor;
    QAction *newFileAction;
    QAction *newFolderAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *renameAction;
    QAction *deleteAction;
    QLabel *currentPathLabel;
    QTreeView *treeView;
    QFileSystemModel *fileSystemModel;
    QSortFilterProxyModel *proxyModel;
    QLineEdit *searchLineEdit;
    QTextEdit *textPreview;
    QLabel *imagePreview;
    QSplitter *splitter;
    QWidget *previewWidget;
    QModelIndex currentContextMenuIndex;
};
