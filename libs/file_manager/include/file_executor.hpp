#pragma once

#include <QObject>
#include <QString>

class FileExecutor : public QObject {
    Q_OBJECT

public:
    explicit FileExecutor(QObject *parent = nullptr);
    ~FileExecutor() override = default;

    QString create_new_file(const QString& dir_path, const QString& name);
    QString create_new_folder(const QString& dir_path, const QString& name);
    QString rename_item(const QString& old_path, const QString& new_name);
    QString delete_item(const QString& path);
    void set_copy_source(const QString& path);
    QString paste(const QString& dest_dir_path);
    bool has_copy_source() const;

private:
    QString m_copy_source_path;
    QString recursive_copy_dir(const QString& source_dir, const QString& dest_dir);
};
