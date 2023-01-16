#include <QCoreApplication>

/*

  What
  sender function

  Description
  Gets the object that emitted the signal

  Why
  Sometimes we need to know where the signal came from

  Example
  Simple server
  QT += network

 */

#include <QDebug>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;

    if(!server.listen(QHostAddress::Any, 3924))
    {
        qCritical() << server.errorString();
    }
    else
    {
        qInfo() << "Server is listening!";
    }


    return a.exec();
}
