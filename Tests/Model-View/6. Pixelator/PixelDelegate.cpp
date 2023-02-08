#include "PixelDelegate.h"

PixelDelegate::PixelDelegate(QObject *parent)
    : QAbstractItemDelegate{parent}
    , pixelSize(12)
{

}

void PixelDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(option.state & QStyle::State_Selected)
        painter->fillRect(option.rect, option.palette.highlight());

    const int size = qMin(option.rect.width(), option.rect.height());
    const int brightness = index.model()->data(index, Qt::DisplayRole).toInt();
    const double radius = (size/2.0) - (brightness/255.0*size/2.0);
    if(qFuzzyIsNull(radius))
        return;

    painter->save();
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(Qt::NoPen);

    if(option.state & QStyle::State_Selected)
        painter->setBrush(option.palette.highlightedText());
    else
        painter->setBrush(option.palette.text());
    painter->drawEllipse(QRectF(option.rect.x() + option.rect.width()/2-radius,
                                option.rect.y() + option.rect.height()/2-radius,
                                2*radius, 2*radius));
    painter->restore();
}

QSize PixelDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option)
    Q_UNUSED(index)

    return QSize(pixelSize, pixelSize);
}

void PixelDelegate::setPixelSize(int size)
{
    pixelSize = size;
}
