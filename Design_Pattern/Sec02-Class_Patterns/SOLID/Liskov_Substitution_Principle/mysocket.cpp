#include "mysocket.h"

MySocket::MySocket(QObject *parent) : QTcpSocket(parent)
{

}

void MySocket::close()
{
    qInfo() << "Do something before closing...";

    // - breaks things!
    // QTcpSocket::close();
}
