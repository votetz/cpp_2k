#include "file_executor.hpp"
#include <QFile>
#include <QDir>
#include <QFileInfo>

FileExecutor::FileExecutor(QObject *parent) : QObject(parent), m_copy_source_path() {}

QString FileExecutor::create_new_file(const QString& dir_path, const QString& name) {
    QString full_path = dir_path + "/" + name;
    QFile file(full_path);
    if (file.exists()) {
        return "File already exists";
    }
    if (!file.open(QIODevice::WriteOnly)) {
        return "Could not create file";
    }
    file.close();
    return "";
}

QString FileExecutor::create_new_folder(const QString& dir_path, const QString& name) {
    QDir dir(dir_path);
    if (!dir.mkdir(name)) {
        return "Could not create folder";
    }
    return "";
}

QString FileExecutor::rename_item(const QString& old_path, const QString& new_name) {
    QFileInfo info(old_path);
    QString new_path = info.absolutePath() + "/" + new_name;
    if (QFile::exists(new_path)) {
        return "Item with this name already exists";
    }
    if (!QFile::rename(old_path, new_path)) {
        return "Could not rename item";
    }
    return "";
}

QString FileExecutor::delete_item(const QString& path) {
    QFileInfo info(path);
    if (info.isDir()) {
        QDir dir(path);
        if (!dir.removeRecursively()) {
            return "Could not delete folder";
        }
    } else {
        if (!QFile::remove(path)) {
            return "Could not delete file";
        }
    }
    return "";
}

void FileExecutor::set_copy_source(const QString& path) {
    m_copy_source_path = path;
}

QString FileExecutor::paste(const QString& dest_dir_path) {
    if (m_copy_source_path.isEmpty()) {
        return "No item to paste";
    }
    QFileInfo source_info(m_copy_source_path);
    QString target_path = dest_dir_path + "/" + source_info.fileName();
    if (source_info.isDir()) {
        return recursive_copy_dir(m_copy_source_path, target_path);
    } else {
        if (QFile::exists(target_path)) {
            return "File already exists";
        }
        if (!QFile::copy(m_copy_source_path, target_path)) {
            return "Could not copy file";
        }
    }
    return "";
}

QString FileExecutor::recursive_copy_dir(const QString& source_dir, const QString& dest_dir) {
    QDir source(source_dir);
    if (!source.exists()) {
        return "Source directory does not exist";
    }
    QDir dest(dest_dir);
    if (dest.exists()) {
        return "Destination directory already exists";
    }
    if (!dest.mkpath(".")) {
        return "Could not create destination directory";
    }
    QFileInfoList entries = source.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
    for (const QFileInfo& entry : entries) {
        QString dest_path = dest_dir + "/" + entry.fileName();
        if (entry.isDir()) {
            QString err = recursive_copy_dir(entry.filePath(), dest_path);
            if (!err.isEmpty()) {
                return err;
            }
        } else {
            if (QFile::exists(dest_path)) {
                return "File " + entry.fileName() + " already exists in destination";
            }
            if (!QFile::copy(entry.filePath(), dest_path)) {
                return "Could not copy file " + entry.fileName();
            }
        }
    }
    return "";
}

bool FileExecutor::has_copy_source() const {
    return !m_copy_source_path.isEmpty();
}
