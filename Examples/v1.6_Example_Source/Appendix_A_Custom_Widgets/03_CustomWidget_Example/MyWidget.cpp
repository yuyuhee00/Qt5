#include "MyWidget.h"
#include <QPainter>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
}

void MyWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter;
    painter.begin(this);

    int w = this->window()->width();
    int h = this->window()->height();

    QPixmap imgPixmap = QPixmap(":/resources/qtblog.png")
                            .scaled(w, h, Qt::KeepAspectRatio);

    int imgWidth = imgPixmap.width();
    int imgHeight = imgPixmap.height();

    int xPos = 0;
    int yPos = 0;

    if(w > imgPixmap.width())
        xPos = (w - imgWidth) / 2;
    else if( h > imgPixmap.height())
        yPos = (h - imgHeight) / 2;

    painter.drawPixmap(xPos, yPos, imgPixmap);

    painter.end();

}
