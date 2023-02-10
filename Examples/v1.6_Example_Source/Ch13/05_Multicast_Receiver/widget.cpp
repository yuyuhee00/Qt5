#include "widget.h"
#include "ui_widget.h"
#include <QtWidgets>
#include <QtNetwork>

Widget::Widget(QWidget *parent) :
    QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    groupAddress4 = QHostAddress(QStringLiteral("239.255.43.21"));
    groupAddress6 = QHostAddress(QStringLiteral("ff12::2115"));

    udpSocket4.bind(QHostAddress::AnyIPv4,
                    45000,
                    QUdpSocket::ShareAddress);
    udpSocket4.joinMulticastGroup(groupAddress4);

    if (!udpSocket6.bind(QHostAddress::AnyIPv6, 45000,
                         QUdpSocket::ShareAddress) ||
            !udpSocket6.joinMulticastGroup(groupAddress6))
        qDebug() << Q_FUNC_INFO << "IPv4 멀티케스트만 사용 가능.";


    // 이전 Signal Slot 스타일
    connect(&udpSocket4, SIGNAL(readyRead()),
            this,        SLOT(readDatagrams()));

    // 새로운 Signal Slot 스타일
    connect(&udpSocket6, &QUdpSocket::readyRead,
            this,        &Widget::readDatagrams);
}

void Widget::readDatagrams()
{
    QByteArray datagram;

    while (udpSocket4.hasPendingDatagrams()) {
        datagram.resize(int(udpSocket4.pendingDatagramSize()));
        udpSocket4.readDatagram(datagram.data(), datagram.size());
        ui->recvMsg->setText(tr("IPv4 수신 datagram : \"%1\"")
                             .arg(datagram.constData()));
    }

    // using QUdpSocket::receiveDatagram (API since Qt 5.8)
    while (udpSocket6.hasPendingDatagrams()) {
        QNetworkDatagram dgram = udpSocket6.receiveDatagram();
        ui->recvMsg->setText(ui->recvMsg->text() +
                             tr("\nIPv6 수신 datagram : \"%1\"")
                             .arg(dgram.data().constData()));
    }
}

Widget::~Widget()
{
    delete ui;
}
