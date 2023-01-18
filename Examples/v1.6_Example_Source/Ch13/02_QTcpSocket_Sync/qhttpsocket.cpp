#include "qhttpsocket.h"
#include <QDebug>

QHttpSocket::QHttpSocket(QObject *parent)
    : QObject(parent)
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(disconnected()),
            this, SLOT(disconnected()));

}

QHttpSocket::~QHttpSocket()
{
}

void QHttpSocket::httpConnect()
{
    qDebug() << Q_FUNC_INFO;
    socket->connectToHost("qt-dev.com", 80);

    if(socket->waitForConnected(5000))
    {
        qDebug() << "TCP Connected.";
        // send
        int writeBytes = socket->write("Hello server\r\n\r\n");
        socket->waitForBytesWritten(1000);

        qDebug() << "write bytes : " << writeBytes;

        socket->waitForReadyRead(3000);

        qDebug() << "Reading: " << socket->bytesAvailable();
        qDebug() << socket->readAll();
    }
    else
    {
        qDebug() << "Not connected!";
    }
}

void QHttpSocket::httpDisconnected()
{
    qDebug() << Q_FUNC_INFO;
}
