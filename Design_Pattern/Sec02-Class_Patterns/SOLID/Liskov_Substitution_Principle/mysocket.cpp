#include "mysocket.h"

MySocket::MySocket(QObject *parent) : QTcpSocket(parent)
{

}


void MySocket::close()
{
    qInfo() << "Do something before closing...";
   //QTcpSocket::close();// - breaks things!
}
