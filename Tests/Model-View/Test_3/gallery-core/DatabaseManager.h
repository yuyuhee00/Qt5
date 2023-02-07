#pragma once

#include <QString>
#include "AlbumDao.h"
#include "PictureDao.h"

class QSqlQuery;
class QSqlDatabase;

const QString DATABASE_FILE_NAME = "gallery.db";

class DatabaseManager
{
public:
    static void debugQuery(const QSqlQuery& query);
    static DatabaseManager& instance();
    ~DatabaseManager();

public:
    DatabaseManager (const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;
    DatabaseManager (const DatabaseManager&&) = delete;
    DatabaseManager& operator=(const DatabaseManager&&) = delete;

private:
    DatabaseManager(const QString& path = DATABASE_FILE_NAME);

private:
    std::unique_ptr<QSqlDatabase> m_database;

public:
    const AlbumDao m_albumDao;
    const PictureDao m_pictureDao;
};

