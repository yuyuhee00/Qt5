#include "CustomWidget.h"
#include <QPainter>
#include <QMouseEvent>


CustomWidget::CustomWidget(QWidget *parent)
    : QWidget(parent)
{
}

CustomWidget::~CustomWidget()
{
}

void CustomWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_lastPos =  event->position().toPoint();
        update();
    }
}

void CustomWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_lastPos =  event->position().toPoint();
        update();
    }
}

void CustomWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect r1 = rect().adjusted(10,10,-10,-10);
    painter.setPen(QColor(51, 229, 181)); //"#33B5E5"));
    painter.drawRect(r1);

    QRect r2(QPoint(0,0), QSize(40,40));
    if(m_lastPos.isNull()) {
        r2.moveCenter(r1.center());
    } else {
        r2.moveCenter(m_lastPos);
    }
    painter.fillRect(r2, QColor(255, 187, 51)); //"#FFBB33"));
}

