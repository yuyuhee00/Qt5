#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QGraphicsItem>

class Shape : public QGraphicsItem
{
public:
    Shape();

public:
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

protected:
    void advance(int step) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QColor m_color;
};

#endif // SHAPE_H
