#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter;
    painter.begin(this);

    int w = this->window()->width();
    int h = this->window()->height();


//    painter.setBrush(QBrush(Qt::green, Qt::Dense3Pattern));
//    painter.setPen(Qt::blue);
//    painter.drawEllipse(10, 10, 100,100);

//    painter.setBrush(Qt::NoBrush);
//    painter.setPen(Qt::blue);
//    painter.drawEllipse(80, 10, 100, 100);

    //-----------

    /*
    QPixmap pixmap(":resources/qtblog.png");
    int w = pixmap.width();
    int h = pixmap.height();
    pixmap.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    */

    QPixmap imgPixmap = QPixmap(":resources/qtblog.png")
                        .scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    int imgWidth = imgPixmap.width();
    int imgHeight = imgPixmap.height();

    int xPos = 0;
    int yPos = 0;

    if(w > imgWidth)
        xPos = (w - imgWidth) / 2;
    else if( h > imgHeight)
        yPos = (h - imgHeight) / 2;


    QBrush brush(imgPixmap);
    painter.setBrush(brush);
    painter.setPen(Qt::blue);
    painter.drawRect(xPos, yPos, imgWidth, imgHeight);

    //-----------

//    QRadialGradient gradient(50, 50, 50, 50, 50);
//    gradient.setColorAt(0, QColor::fromRgbF(0, 1, 0, 1));
//    gradient.setColorAt(1, QColor::fromRgbF(0, 0, 0, 0));
//    QBrush brush(gradient);

//    painter.setBrush(brush);
//    painter.drawRect(0, 0, 100, 100);

    painter.end();
}

Widget::~Widget()
{
}
