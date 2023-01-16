#include <QCoreApplication>

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

#include <QObject>
#include <QDebug>
#include "producer.h"
#include "consumer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Producer producer;
    Consumer consumer;

    //Connect the objects
    QObject::connect(&producer, &Producer::readyProduct, &consumer, &Consumer::readyProduct);
    QObject::connect(&a, &QCoreApplication::aboutToQuit, &producer, &Producer::stop);

    producer.start();

    return a.exec();
}
