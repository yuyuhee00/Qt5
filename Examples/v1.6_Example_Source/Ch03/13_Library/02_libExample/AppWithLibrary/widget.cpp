#include "widget.h"
#include "ui_widget.h"
#include "myutil.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pbtSum, SIGNAL(pressed()),
            this, SLOT(slotBtnClick()));
}

void Widget::slotBtnClick()
{
    qint32 arg1 = ui->leArg1->text().toInt();
    qint32 arg2 = ui->leArg2->text().toInt();

    MyUtil *myUtil = new MyUtil();
    qint32 sumValue = myUtil->getSumValue(arg1, arg2);

    ui->leSum->setText(QString("%1").arg(sumValue));
}

Widget::~Widget()
{
    delete ui;
}
