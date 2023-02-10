// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "mymodel.h"
#include <QTime>

MyModel::MyModel(QObject *parent)
    : QAbstractTableModel(parent)
    , timer(new QTimer(this))
{
    timer->setInterval(1000);
    QObject::connect(timer, &QTimer::timeout , this, &MyModel::timerHit);
    timer->start();
}

int MyModel::rowCount(const QModelIndex & /*parent */) const
{
    return 2;
}

int MyModel::columnCount(const QModelIndex & /*parent */) const
{
    return 3;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

    if (role == Qt::DisplayRole && row == 0 && col == 0)
        return QTime::currentTime().toString();

    return QVariant();
}

void MyModel::timerHit()
{
    // we identify the top left cell
    QModelIndex topLeft = QAbstractItemModel::createIndex(0, 0);

    // emit a signal to make the view reread identified data
    emit QAbstractItemModel::dataChanged(topLeft, topLeft, {Qt::DisplayRole});
}

