#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    groupAddress4 = QHostAddress(QStringLiteral("239.255.43.21"));
    groupAddress6 = QHostAddress(QStringLiteral("ff12::2115"));

    timer = new QTimer(this);
    udpSocket4.bind(QHostAddress(QHostAddress::AnyIPv4), 0);
    udpSocket6.bind(QHostAddress(QHostAddress::AnyIPv6), udpSocket4.localPort());

    msgNumber = 1;

    connect(ui->startButton, SIGNAL(clicked()),
            this, SLOT(startButton()));

    connect(timer, SIGNAL(timeout()),
            this, SLOT(multicastSend()));
}

void Widget::startButton()
{
    if(!timer->isActive())
        timer->start(1000);
}

void Widget::multicastSend()
{
    ui->sendMsg->setText(QString("전송 메세지 %1").arg(msgNumber));

    QByteArray datagram = "멀티케스트 번호 "
                            + QByteArray::number(msgNumber);

    udpSocket4.writeDatagram(datagram, groupAddress4, 45000);
    if (udpSocket6.state() == QAbstractSocket::BoundState)
        udpSocket6.writeDatagram(datagram, groupAddress6, 45000);

    msgNumber++;
}

Widget::~Widget()
{
    delete ui;
}
