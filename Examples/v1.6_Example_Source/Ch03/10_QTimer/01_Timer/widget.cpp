#include "widget.h"
#include "ui_widget.h"
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pbtStart, &QPushButton::pressed, this, &Widget::startPressed);
    connect(ui->pbtStop,  &QPushButton::pressed, this, &Widget::stopPressed);

    ui->pbtStart->setEnabled(true);
    ui->pbtStop->setEnabled(false);

    m_timer = new QTimer();
    connect(m_timer, &QTimer::timeout, this, &Widget::elapsedTime);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::startPressed()
{
    ui->pbtStart->setEnabled(false);
    ui->pbtStop->setEnabled(true);

    m_timer->start(1000);
}

void Widget::stopPressed()
{
    ui->pbtStart->setEnabled(true);
    ui->pbtStop->setEnabled(false);

    m_timer->stop();
}

void Widget::elapsedTime()
{
    QDateTime curr;
    curr = QDateTime::currentDateTime();

    QString timeStr = curr.toString("현재시간 yyyy-MM-dd hh:mm:ss");
    ui->leCurrentTime->setText(timeStr);
}
