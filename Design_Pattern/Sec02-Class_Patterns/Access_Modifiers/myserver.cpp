#include "myserver.h"

MyServer::MyServer(QObject *parent) : QTcpServer(parent)
{

}

void MyServer::handleSocket(QTcpSocket *socket)
{
    if(!socket) return;
    socket->write("Hello World\r\n");
    socket->waitForBytesWritten();
    socket->close();
    delete socket;
}


void MyServer::incomingConnection(qintptr handle)
{
    QTcpSocket *socket = new QTcpSocket(this);
    socket->setSocketDescriptor(handle);
    handleSocket(socket);
}
