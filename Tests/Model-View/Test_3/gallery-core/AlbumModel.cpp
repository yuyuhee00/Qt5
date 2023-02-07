#include "AlbumModel.h"

AlbumModel::AlbumModel(QObject *parent)
    : QAbstractListModel(parent)
    , m_database(DatabaseManager::instance())
    , m_albums(DatabaseManager::instance().m_albumDao.albums())
{
}

 QModelIndex AlbumModel::addAlbum(const Album& album)
 {
    int rowIndex = rowCount();

    this->beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    albumT newAlbum(std::make_unique<Album>(album));
    m_database.m_albumDao.addAlbum(*newAlbum);
    m_albums->push_back(std::move(newAlbum));
    this->endInsertRows();

    return this->index(rowIndex, 0);
 }

 QHash<int, QByteArray> AlbumModel::roleNames() const
 {
    QHash<int, QByteArray> roles;
    roles[Roles::IdRole] = "id";
    roles[Roles::NameRole] = "name";
    return roles;
 }

int AlbumModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_albums->size();
}

QVariant AlbumModel::data(const QModelIndex &index, int role) const
{
    if (!this->isIndexValid(index))
        return QVariant();

    const Album& album = *m_albums->at(index.row());
    switch(role) {
    case Roles::IdRole:
        return album.id();
    case Roles::NameRole:
    case Qt::DisplayRole:
        return album.name();
    default:
        return QVariant();
    }

    return QVariant();
}

bool AlbumModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!this->isIndexValid(index) || role != Roles::NameRole)
        return false;

    Album& album = *(m_albums->at(index.row()));
    album.setName(value.toString());
    m_database.m_albumDao.updateAlbum(album);
    emit this->dataChanged(index, index);
    return true;
}

bool AlbumModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if(row < 0 || row >= rowCount() || count < 0 || (row+count) > rowCount())
        return false;

    this->beginRemoveRows(parent, row, row + count - 1);
    int countLeft = count;
    while(countLeft--) {
        const Album& album = *(m_albums->at(row+countLeft));
        m_database.m_albumDao.removeAlbum(album.id());
    }
    m_albums->erase(m_albums->begin() + row, m_albums->begin() + row + count);
    this->endRemoveRows();
    return true;
}

   bool AlbumModel::isIndexValid(const QModelIndex& index) const
{
    return index.isValid() && index.row() < rowCount();
}
