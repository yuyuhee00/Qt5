#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include "person.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::pressed, this, &Widget::buttonPressed);

    goodman = new Person();
    connect(goodman, &Person::nameChanged, this, &Widget::nameChanged);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::buttonPressed()
{
    QString name = ui->leName->text();
    goodman->setProperty("name", name);
}

void Widget::nameChanged(const QString &n)
{
    qDebug() << Q_FUNC_INFO << "Name Changed : " << n;

    QVariant myName = goodman->property("name");
    qDebug() << "My name is " << myName.toString();
}


