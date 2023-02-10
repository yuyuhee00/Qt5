#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QAbstractItemModel>
#include <QStringListModel>
#include <QListView>
#include <QTableView>
#include <QTreeView>
#include <QSplitter>

class StringListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    StringListModel(const QStringList& strings, QObject* parent = nullptr)
        : QAbstractListModel(parent)
        , stringList(strings) {}


private:
    QStringList stringList;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;/*
    bool setItemData(const QModelIndex &index, const QMap<int, QVariant> &roles) override;
    bool removeRows(int row, int count, const QModelIndex &parent) override;*/
};

#endif // WIDGET_H
