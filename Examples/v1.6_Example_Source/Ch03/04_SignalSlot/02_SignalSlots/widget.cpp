#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pbtButton, SIGNAL(pressed()),
            this, SLOT(slotPbtButtonClick()));

    cnt1 = new Counter("counter 1");
    cnt2 = new Counter("counter 2");

//    connect(cnt1, SIGNAL(valueChagned(int)),
//            cnt2, SLOT(setValue(int)));

    connect(cnt1, SIGNAL(valueChagned(int)),
            cnt2, SIGNAL(valueChagned(int)));

    connect(cnt2, SIGNAL(valueChagned(int)),
            cnt2, SLOT(setValue(int)));

}

void Widget::slotPbtButtonClick()
{
    qint32 num = ui->leNumber->text().toInt();

    emit cnt1->valueChagned(num);
}

Widget::~Widget()
{
    delete ui;
}

