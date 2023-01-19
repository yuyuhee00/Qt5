#include <QtGui>
#include "ellipseitem.h"
#include <QDebug>

EllipseItem::EllipseItem(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
}

void EllipseItem::paint(QPainter *painter)
{
    const qreal halfPenWidth = qMax(painter->pen().width() / 2.0, 1.0);
    
    QRectF rect = boundingRect();

    // adjust는 사각형 영역의 모서리 영역에 그려지는 선과 같은 1px 이 가려지는
    // 것을 방지하기 위한 목적으로 사용
    rect.adjust(halfPenWidth, halfPenWidth, -halfPenWidth, -halfPenWidth);
    
    painter->drawEllipse(rect);
}
