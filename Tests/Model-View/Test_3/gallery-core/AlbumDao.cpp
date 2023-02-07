#include "AlbumDao.h"
#include "Album.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include "DatabaseManager.h"

AlbumDao::AlbumDao(QSqlDatabase& database)
    : m_database(database)
{
}

AlbumDao::~AlbumDao()
{}

void AlbumDao::init() const
{
    if(!m_database.tables().contains("albums"))
    {
        QSqlQuery query(m_database);
        query.exec("CREATE TABLE albums (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)");
        DatabaseManager::debugQuery(query);
    }
}

void AlbumDao::addAlbum(Album &album) const
{
    QSqlQuery query(m_database);
    query.prepare("INSERT INTO albums (name) VALUES (:name)");
    query.bindValue(":name", album.name());
    query.exec();

    // Change Album's id to last ID of database
    album.setId(query.lastInsertId().toInt());
}

void AlbumDao::updateAlbum(const Album &album) const
{
    QSqlQuery query(m_database);
    query.prepare("UPDATE albums SET name = (:name) WHERE id = (:id)");
    query.bindValue(":name", album.name());
    query.bindValue(":id", album.id());
    query.exec();
    DatabaseManager::debugQuery(query);
}

void AlbumDao::removeAlbum(int id) const
{
    QSqlQuery query(m_database);
    query.prepare("DELETE FROM albums WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
    DatabaseManager::debugQuery(query);
}

//QVector<Album *> AlbumDao::albums() const
//{
//    QSqlQuery query("SELECT * FROM albums", m_database);
//    query.exec();

//    QVector<Album*> albums;
//    while(query.next())
//    {
//        Album* album = new Album();
//        album->setId(query.value("id").toInt());
//        album->setName(query.value("name").toString());
//        albums.append(album);
//    }
//    return albums;
//}

albumsT AlbumDao::albums() const
{
    QSqlQuery query("SELECT * FROM albums", m_database);
    query.exec();

    auto albums = std::unique_ptr<albumVec>();
    while(query.next()) {
        albumT album = std::unique_ptr<Album>();
        album->setId(query.value("id").toInt());
        album->setName(query.value("name").toString());
        albums->push_back(std::move(album));
    }

    return albums;
}
