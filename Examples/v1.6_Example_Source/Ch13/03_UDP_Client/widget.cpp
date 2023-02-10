#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

#define SERVER_PORT 21000
#define CLIENT_PORT 22000

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->sendButton, &QPushButton::pressed,
            this,           &Widget::sendButton);

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress("192.168.100.110"), CLIENT_PORT);

    connect(udpSocket, SIGNAL(readyRead()),
            this,      SLOT(readPendingDatagram()));
}

void Widget::sendButton()
{
    QByteArray msg;
    msg = ui->sendMsg->text().toLocal8Bit();

    QHostAddress sender("192.168.100.110");
    udpSocket->writeDatagram(msg, sender, SERVER_PORT);
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
}

Widget::~Widget()
{
    delete ui;
}

