/*

  What
  Signals and slots

  Description
  The moc that connects objects

  Why
  Inter-object communication

  Exmaple
  Simple example of signals and slots
  look at MOC

  /home/rootshell/Code/Qt/build-qt5dp-5-1-Desktop_Qt_5_12_3_GCC_64bit-Debug
  Look at the MOC files
  look at the CPP files for each

*/

#include <QCoreApplication>
#include <QObject>
#include <QDebug>
#include "producer.h"
#include "consumer.h"
#include "SignalsAndSlots.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Producer producer;
//    QObject::connect(&a, &QCoreApplication::aboutToQuit, &producer, &Producer::stop);

    Consumer consumer;

    ConnectProduerToConsumer(producer, consumer);

    producer.start();

    return a.exec();
}
