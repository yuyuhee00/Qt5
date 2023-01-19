#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

// Basic Drawing
void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter;
    painter.begin(this);

    int w = this->window()->width();
    int h = this->window()->height();


    /*
    QImage image = QImage(":/images/picture.png")
                        .scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    int imgWidth = image.width();
    int imgHeight = image.height();

    int xPos = 0;
    int yPos = 0;

    if(w > imgWidth)
        xPos = (w - imgWidth) / 2;
    else if( h > imgHeight)
        yPos = (h - imgHeight) / 2;

    painter.drawImage(xPos, yPos, image);
    */
    /*
    QPixmap imgPixmap = QPixmap(":/images/picture.png")
                        .scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    int imgWidth = imgPixmap.width();
    int imgHeight = imgPixmap.height();

    int xPos = 0;
    int yPos = 0;

    if(w > imgPixmap.width())
        xPos = (w - imgWidth) / 2;
    else if( h > imgPixmap.height())
        yPos = (h - imgHeight) / 2;

    painter.drawPixmap(xPos, yPos, imgPixmap);
    */

    painter.setPen(Qt::blue);
    painter.drawLine(10, 10, w-100, h-40); // 선
    painter.drawRect(120, 10, 80, 80); // 사각형

    QRectF rect(230.0, 10.0, 80.0, 80.0);
    painter.drawRoundedRect(rect, 20, 20); // 둥근 사각형

    QPointF p1[3] = {
                    QPointF(10.0, 110.0),
                    QPointF(110.0, 110.0),
                    QPointF(110.0, 190.0)
                    };
    painter.drawPolyline(p1, 3); // 포인트 지점을 선으로 그리기

    QPointF p2[3] = {
                    QPointF(120.0, 110.0),
                    QPointF(220.0, 110.0),
                    QPointF(220.0, 190.0)
                    };
    painter.drawPolygon(p2, 3); // 포인트 지점으로 도형그리기

    painter.setFont(QFont("Arial", 16)); // 폰트지정
    painter.setPen(Qt::black);
    QRect font_rect(10, 150, 420, 180); // 텍스트를 표시할 영역
    painter.drawText(font_rect, Qt::AlignCenter, "Qt 개발자 커뮤니티(http://www.qt-dev.com)");

    painter.end();
}
