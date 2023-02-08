#pragma once

#include <QAbstractItemDelegate>
#include <QPainter>

class PixelDelegate : public QAbstractItemDelegate
{
    Q_OBJECT

public:
    explicit PixelDelegate(QObject *parent = nullptr);

// QAbstractItemDelegate interface
public:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;

public slots:
    void setPixelSize(int size);

private:
    int pixelSize;
};

