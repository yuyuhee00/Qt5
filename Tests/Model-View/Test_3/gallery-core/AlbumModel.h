#pragma once

#include <QAbstractListModel>
#include "gallery-core_global.h"
#include "Album.h"
#include "DatabaseManager.h"
#include "CommonTypes.h"

class GALLERYCORE_EXPORT AlbumModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole,
    };

public:
    explicit AlbumModel(QObject *parent = nullptr);

public:
    QModelIndex addAlbum(const Album& album);

    // QAbstractItemModel interface
     QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

private:
    bool isIndexValid(const QModelIndex& index) const;

private:
    DatabaseManager& m_database;
    albumsT m_albums;
};

