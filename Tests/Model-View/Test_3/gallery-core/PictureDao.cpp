#include "PictureDao.h"
#include "Picture.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include "DatabaseManager.h"

PictureDao::PictureDao(QSqlDatabase& database)
    : m_database(database)
{
}

PictureDao::~PictureDao()
{}

void PictureDao::init() const
{
    if(!m_database.tables().contains("pictures"))
    {
        QSqlQuery query(m_database);
        query.exec(QString("CREATE TABLE albums")
                            + " (id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            + "album_id INTEGER, "
                            + "url TEXT)" );
    }
}

void PictureDao::addPictureInAlbum(int albumId, Picture &picture) const
{
    QSqlQuery query(m_database);
    query.prepare(QString("INSERT INTO pictures")
        + " (album_id, url)"
        + " VALUES ("
        + ":album_id, "
        + ":url"
        + ")");
    query.bindValue(":album_id", albumId);
    query.bindValue(":url", picture.fileUrl());
    query.exec();
    DatabaseManager::debugQuery(query);
    picture.setId(query.lastInsertId().toInt());
    picture.setAlbumId(albumId);
}

void PictureDao::removePicture(int id) const
{
    QSqlQuery query(m_database);
    query.prepare("DELETE FROM pictures WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
    DatabaseManager::debugQuery(query);
}

void PictureDao::removePicturesForAlbum(int albumId) const
{
    QSqlQuery query(m_database);
    query.prepare("DELETE FROM pictures WHERE album_id = (:album_id)");
    query.bindValue(":album_id", albumId);
    query.exec();
    DatabaseManager::debugQuery(query);
}

//QSqlQuery query(mDatabase);
//query.prepare("SELECT * FROM pictures WHERE album_id = (:album_id)");
//query.bindValue(":album_id", albumId);
//query.exec();
//DatabaseManager::debugQuery(query);
////std::unique_ptr<std::vector<std::unique_ptr<Picture>>> list(new std::vector<std::unique_ptr<Picture>>());
//using picture_T = std::unique_ptr<Picture>;
//using picture_Vec = std::vector<picture_T >;
//std::unique_ptr<picture_Vec> list(std::make_unique<picture_Vec>());
//while(query.next()) {
//    //std::unique_ptr<Picture> picture(new Picture());
//    picture_T picture(std::make_unique<Picture>());
//    picture->setId(query.value("id").toInt());
//    picture->setAlbumId(query.value("album_id").toInt());
//    picture->setFileUrl(query.value("url").toString());
//    list->push_back(std::move(picture));
//}
//return list;

picturesT PictureDao::picturesForAlbum(int albumId) const
{
    QSqlQuery query(m_database);
    query.prepare("SELECT * FROM picures WHERE album_id = (:album_id)");
    query.bindValue(":album_id", albumId);
    query.exec();
    DatabaseManager::debugQuery(query);

    auto pictures= std::unique_ptr<pictureVec>();
    while(query.exec()) {
        auto picture = std::unique_ptr<Picture>();
        picture->setId(query.value("id").toInt());
        picture->setAlbumId(query.value("alum_id").toInt());
        picture->setFileUrl(query.value("url").toString());
        pictures->push_back(std::move(picture));
    }

    return pictures;
}
