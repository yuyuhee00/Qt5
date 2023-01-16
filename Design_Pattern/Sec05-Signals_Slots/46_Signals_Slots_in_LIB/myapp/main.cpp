#include <QCoreApplication>

/*

  What
  Signals and slots inside of libs

  Description
  Works great across libs

  Why
  Some times people become confused about using libs

  Example
  MyLib / MyApp
  CONFIG += ordered
  add library


 */

#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client;
    client.start();

    return a.exec();
}
