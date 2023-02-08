#include "SingleListModel.h"

int StringListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return stringList.count();
}

QVariant StringListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();
    if(index.row() > stringList.size()) return QVariant();

    if(role == Qt::DisplayRole)
        return stringList.at(index.row());
    else
        return QVariant();
}

QVariant StringListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole) return QVariant();

    if(orientation == Qt::Horizontal)
        return QStringLiteral("Column %1").arg(section);
    else
        return QStringLiteral("Row %1").arg(section);
}

//bool StringListModel::setItemData(const QModelIndex &index, const QMap<int, QVariant> &roles)
//{

//}

//bool StringListModel::removeRows(int row, int count, const QModelIndex &parent)
//{

//}
