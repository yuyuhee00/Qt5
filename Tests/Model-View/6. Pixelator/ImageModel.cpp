#include "ImageModel.h"

ImageModel::ImageModel(QObject *parent)
    : QAbstractTableModel{parent}
{

}

void ImageModel::setImage(const QImage &newModelImage)
{
    beginResetModel();
    modelImage = newModelImage;
    endResetModel();
}

int ImageModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return modelImage.height();
}

int ImageModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return modelImage.width();
}

QVariant ImageModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

    return qGray(modelImage.pixel(index.column(), index.row()));
}

QVariant ImageModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    Q_UNUSED(section)
    Q_UNUSED(orientation)

    if(role == Qt::SizeHintRole)
        return QSize(1, 1);

    return QVariant();
}
