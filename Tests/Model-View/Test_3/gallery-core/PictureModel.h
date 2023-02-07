#pragma once

#include <QAbstractListModel>
#include "gallery-core_global.h"
#include "Picture.h"
#include "DatabaseManager.h"
#include "CommonTypes.h"
#include "AlbumModel.h"

class GALLERYCORE_EXPORT PictureModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        UrlRole = Qt::UserRole + 1,
        FilePathRole
    };

public:
    explicit PictureModel(const AlbumModel& albumModel, QObject* parent = nullptr);

public:
    QModelIndex addPicture(const Picture& picture);
    void setAlbumId(int albumId);
    void clearAlbum();

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool removeRows(int row, int count, const QModelIndex &parent) override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void deletePicturesForAlbum();

private:
    void loadPictures(int albumId);
    bool isIndexValid(const QModelIndex& index) const;

private:
    int m_albumID;
    DatabaseManager& m_database;
    picturesT m_pictures;
};

