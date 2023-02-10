#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ImageButton *imgBtn1 = new ImageButton(this);
    ImageButton *imgBtn2 = new ImageButton(this);

    QHBoxLayout *hLay = new QHBoxLayout(this);
    hLay->addWidget(imgBtn1);
    hLay->addWidget(imgBtn2);

    setLayout(hLay);
    connect(imgBtn1, &ImageButton::clicked,
            this,    &Widget::clicked);

    imgBtn2->setDisabled(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::clicked()
{
    qDebug() << Q_FUNC_INFO;
}


