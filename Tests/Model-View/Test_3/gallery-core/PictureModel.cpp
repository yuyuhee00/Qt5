#include "PictureModel.h"

PictureModel::PictureModel(const AlbumModel& albumModel, QObject* parent)
    : QAbstractListModel(parent)
    , m_albumID(-1)
    , m_database(DatabaseManager::instance())
    , m_pictures(std::make_unique<pictureVec>())
{
    connect(&albumModel, &AlbumModel::rowsRemoved, this, &PictureModel::deletePicturesForAlbum);
}

QModelIndex PictureModel::addPicture(const Picture& picture)
{
    int rows = rowCount();

    this->beginInsertRows(QModelIndex(), rows, rows);
    pictureT newPicture = std::make_unique<Picture>(picture);
    m_database.m_pictureDao.addPictureInAlbum(m_albumID, *newPicture);
    m_pictures->push_back(std::move(newPicture));
    this->endInsertRows();

    return this->index(rows, 0);
}

void PictureModel::setAlbumId(int albumId)
{
    this->beginResetModel();
    m_albumID = albumId;
    loadPictures(m_albumID);
    this->endResetModel();
}

void PictureModel::clearAlbum()
{
    setAlbumId(-1);
}

void PictureModel::deletePicturesForAlbum()
{
    m_database.m_pictureDao.removePicturesForAlbum(m_albumID);
    clearAlbum();
}

int PictureModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_pictures->size();
}

QVariant PictureModel::data(const QModelIndex &index, int role) const
{
    if (!isIndexValid(index)) {
        return QVariant();
    }

    const Picture& picture = *(m_pictures->at(index.row()));
    switch (role) {
        case Qt::DisplayRole:
            return picture.fileUrl().fileName();
            break;

        case Roles::UrlRole:
            return picture.fileUrl();
            break;

        case Roles::FilePathRole:
            return picture.fileUrl().toLocalFile();
            break;


        default:
            return QVariant();
    }
}

bool PictureModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if (row < 0
            || row >= rowCount()
            || count < 0
            || (row + count) > rowCount()) {
        return false;
    }

    beginRemoveRows(parent, row, row + count - 1);
    int countLeft = count;
    while(countLeft--) {
        const Picture& picture = *(m_pictures->at(row + countLeft));
        m_database.m_pictureDao.removePicture(picture.id());
    }
    m_pictures->erase(m_pictures->begin() + row, m_pictures->begin() + row + count);
    endRemoveRows();

    return true;
}

QHash<int, QByteArray> PictureModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::DisplayRole] = "name";
    roles[Roles::FilePathRole] = "filepath";
    roles[Roles::UrlRole] = "url";
    return roles;
}

void PictureModel::loadPictures(int albumId)
{
    if(albumId <= 0) {
        // m_pictures.reset(new std::vector<unique_ptr<Picture>>());
        m_pictures = std::make_unique<pictureVec>();
        return;
    }

    m_pictures = m_database.m_pictureDao.picturesForAlbum(albumId);
}

bool PictureModel::isIndexValid(const QModelIndex& index) const
{
    if (index.row() < 0
            || index.row() >= rowCount()
            || !index.isValid()) {
        return false;
    }
    return true;
}
