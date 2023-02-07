#include "ThumbnailProxyModel.h"
#include "PictureModel.h"

const unsigned int THUMBNAIL_SIZE = 350;

ThumbnailProxyModel::ThumbnailProxyModel(QObject *parent)
    : QIdentityProxyModel{parent}
{
}

PictureModel* ThumbnailProxyModel::pictureModel() const
{
    return static_cast<PictureModel*>(this->sourceModel());
}

QVariant ThumbnailProxyModel::data(const QModelIndex &index, int role) const
{
    if(role != Qt::DecorationRole) {
        return QIdentityProxyModel::data(index, role);
    }

    QString filePath = this->sourceModel()->data(index, PictureModel::Roles::FilePathRole).toString();
    return *m_thumbnails[filePath];
}

void ThumbnailProxyModel::setSourceModel(QAbstractItemModel *sourceModel)
{
    QIdentityProxyModel::setSourceModel(sourceModel);
    if(!sourceModel) return;

    QObject::connect(sourceModel, &QAbstractItemModel::modelReset, [this]() { reloadThumbnails(); });
    QObject::connect(sourceModel, &QAbstractItemModel::rowsInserted,
                     [this](const QModelIndex& parent, int first, int last) { generateThumbnails(this->index(first, 0), last-first+1);  });
}

void ThumbnailProxyModel::generateThumbnails(const QModelIndex& startIndex, int count)
{
    if(!startIndex.isValid()) return;

    const QAbstractItemModel* model = startIndex.model();
    int lastIndex = startIndex.row() + count;
    for(int row = startIndex.row(); row < lastIndex; row++) {
        QString filePath = model->data(model->index(row, 0), PictureModel::Roles::FilePathRole).toString();
        QPixmap pixmap(filePath);
        auto thumbnail = new QPixmap(pixmap.scaled(THUMBNAIL_SIZE, THUMBNAIL_SIZE, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        m_thumbnails.insert(filePath, thumbnail);
    }
}

void ThumbnailProxyModel::reloadThumbnails()
{
    qDeleteAll(m_thumbnails);
    m_thumbnails.clear();
    generateThumbnails(this->index(0, 0), this->rowCount());
}
