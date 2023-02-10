#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

#define SERVER_PORT 21000

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress("192.168.100.110"), SERVER_PORT);

    connect(udpSocket, SIGNAL(readyRead()),
            this,      SLOT(readPendingDatagram()));
}

void Widget::readPendingDatagram()
{
    QByteArray buffer;
    buffer.resize(udpSocket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    udpSocket->readDatagram(buffer.data(), buffer.size(),
                         &sender, &senderPort);

    QString msg = QString("Receive IP/PORT : %1 / %2 <br>"
                          "Receive Message: %3 <br>")
                        .arg(sender.toString())
                        .arg(senderPort)
                        .arg(buffer.data());

    ui->textEdit->append(msg);

    QByteArray writeData;
    writeData.append("SERVER : Hello UDP Client.~ ");
    udpSocket->writeDatagram(writeData, sender, senderPort);

}

Widget::~Widget()
{
    delete ui;
}
