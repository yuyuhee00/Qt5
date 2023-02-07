#pragma once

#include <QStyledItemDelegate>
#include <QPainter>

class PIctureDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit PIctureDelegate(QObject *parent = nullptr);

    // QAbstractItemDelegate interface
public:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

