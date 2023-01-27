#include "PictureModel.h"

#include "Album.h"
#include "DatabaseManager.h"
#include "AlbumModel.h"

using namespace std;

PictureModel::PictureModel(const AlbumModel& albumModel, QObject* parent) :
    QAbstractListModel(parent),
    mDb(DatabaseManager::instance()),
    mAlbumId(-1),
    mPictures(std::make_unique<std::vector<std::unique_ptr<Picture>>>())
{
    connect(&albumModel, &AlbumModel::rowsRemoved, this, &PictureModel::deletePicturesForAlbum);
}

QModelIndex PictureModel::addPicture(const Picture& picture)
{
    int rows = rowCount();
    beginInsertRows(QModelIndex(), rows, rows);
    std::unique_ptr<Picture>newPicture = std::make_unique<Picture>(picture);
    mDb.pictureDao.addPictureInAlbum(mAlbumId, *newPicture);
    mPictures->push_back(std::move(newPicture));
    endInsertRows();
    return index(rows, 0);
}

int PictureModel::rowCount(const QModelIndex& /*parent*/) const
{
    return mPictures->size();
}

QVariant PictureModel::data(const QModelIndex& index, int role) const
{
    if (!isIndexValid(index)) {
        return QVariant();
    }

    const Picture& picture = *mPictures->at(index.row());
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

bool PictureModel::removeRows(int row, int count, const QModelIndex& parent)
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
        const Picture& picture = *mPictures->at(row + countLeft);
        mDb.pictureDao.removePicture(picture.id());
    }
    mPictures->erase(mPictures->begin() + row, mPictures->begin() + row + count);
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

void PictureModel::setAlbumId(int albumId)
{
    beginResetModel();
    mAlbumId = albumId;
    loadPictures(mAlbumId);
    endResetModel();
}

void PictureModel::clearAlbum()
{
    setAlbumId(-1);
}

void PictureModel::deletePicturesForAlbum()
{
    mDb.pictureDao.removePicturesForAlbum(mAlbumId);
    clearAlbum();
}

void PictureModel::loadPictures(int albumId)
{
    if (albumId <= 0) {
        //mPictures.reset(new std::vector<unique_ptr<Picture>>());
        mPictures = std::make_unique<std::vector<unique_ptr<Picture>>>();
        return;
    }
    mPictures = mDb.pictureDao.picturesForAlbum(albumId);
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
