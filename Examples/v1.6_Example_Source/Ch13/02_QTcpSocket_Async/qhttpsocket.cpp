#include "qhttpsocket.h"
#include <QDebug>

QHttpSocket::QHttpSocket(QObject *parent)
    : QObject(parent)
{
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()),
            this,   SLOT(slotConnected()));
    connect(socket, SIGNAL(disconnected()),
            this,   SLOT(slotDisconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)),
            this,   SLOT(slotBytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()),
            this,   SLOT(slotReadPandingDatagram()));
}

QHttpSocket::~QHttpSocket()
{
}

void QHttpSocket::httpConnect()
{
    socket->connectToHost("qt-dev.com", 80);
    if(!socket->waitForConnected(3000))
    {
        qDebug() << "Socket Error : "
                 << socket->errorString();
    }
}

void QHttpSocket::slotConnected()
{
    qDebug("\n [%s] CONNECTED", Q_FUNC_INFO);
    socket->write("HEAD / HTTP/1.0\r\n\r\n\r\n\r\n");
}

void QHttpSocket::slotDisconnected()
{
    qDebug("\n [%s] DISCONNECTED", Q_FUNC_INFO);
}

void QHttpSocket::slotBytesWritten(qint64 bytes)
{
    qDebug("\n [%s] Bytes Written [size :%d]",
           Q_FUNC_INFO, bytes);
}

void QHttpSocket::slotReadPandingDatagram()
{
    qDebug() << socket->readAll();
}

























