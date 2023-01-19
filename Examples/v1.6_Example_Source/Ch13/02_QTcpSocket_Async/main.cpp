#include <QCoreApplication>
#include "qhttpsocket.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHttpSocket *httpSocket = new QHttpSocket();
    httpSocket->httpConnect();

    return a.exec();
}
