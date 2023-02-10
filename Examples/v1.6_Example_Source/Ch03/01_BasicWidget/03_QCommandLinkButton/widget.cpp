#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(QSize(300, 100));

    cmmBtn = new QCommandLinkButton("Vision", "Vision Project", this);
    cmmBtn->setFlat(true);

    connect(cmmBtn, SIGNAL(clicked()), this, SLOT(clickFunc()));
}

Widget::~Widget()
{
}

void Widget::clickFunc()
{
    qDebug("QCommandLinkButton Click.");
}


