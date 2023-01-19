#include "widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    this->resize(350, 200);

    QPushButton *btn = new QPushButton("Button", this);
    connect(btn, &QPushButton::pressed, this, &Widget::btnClicked);
    btn->setGeometry(10, 10, 100, 30);

    m_animation = new QPropertyAnimation(btn, "geometry", this);

    m_animation->setDuration(3000); // 3초(단위 밀리세컨드)
    m_animation->setStartValue(QRect(10, 10, 100, 30)); // 시작 좌표
    m_animation->setEndValue(QRect(200, 150, 100, 30)); // 끝나는 좌표

    // m_animation->setEasingCurve(QEasingCurve::OutInQuart);
}

void Widget::btnClicked()
{
    m_animation->start();
}

Widget::~Widget()
{
}


void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter;
    painter.begin(this);

    int w = this->window()->width();
    int h = this->window()->height();

    int xPos = w - 10 - 100;
    int yPos = h - 10 - 30;
    m_animation->setEndValue(QRect(xPos, yPos, 100, 30)); // 끝나는 좌표
    m_animation->setEasingCurve(QEasingCurve::InOutQuad);

    painter.end();
}
