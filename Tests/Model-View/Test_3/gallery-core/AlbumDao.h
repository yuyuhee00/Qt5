#pragma once
#include <QVector>
#include "CommonTypes.h"

class QSqlDatabase;
class Album;

class AlbumDao
{
public:
    explicit AlbumDao(QSqlDatabase& database);
    ~AlbumDao();

    void init() const;
    void addAlbum(Album& album) const;
    void updateAlbum(const Album& album) const;
    void removeAlbum(int id) const;
    //QVector<Album*> albums() const;
    albumsT albums() const;

private:
    QSqlDatabase& m_database;
};

