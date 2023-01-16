#include <QCoreApplication>

/*

  What
  Detecting child events

  Description
  Overriding child events in QObject

  Why
  Connecting a lot of signals can be time consuming

  Example
  Parent and Child

 */

#include <QDebug>
#include "client.h"
#include "server.h"
#include "AutoConnect.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client;
    Server server;

    AutoConnect::connect(&client, &server);

    // test them
    emit client.connected();
    emit client.readyRead();
    client.testing(); // emit test()
    emit client.disconnected();

    return a.exec();
}
