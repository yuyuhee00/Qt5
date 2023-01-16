#include <QCoreApplication>

/*

  What
  Mediator design pattern

  Description
  A mediator is responsible for controlling and coordinating the interactions of a group of objects.

  Why
  Need to send and receive notificions between objects

  Example
  Signals and slots make this simple!
  Qt acts as the mediator

 */

#include "manager.h"
#include "developer.h"
#include "marketing.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Manager manager;
    Marketing marketing;
    QList<Developer*> developers;

    for(int i = 0; i < 5; i++)
    {
        Developer *dev = new Developer(&manager);
        developers.append(dev);

        QObject::connect(&manager, &Manager::getToWork, dev,&Developer::createPrograms);

        QObject::connect(dev, &Developer::completed, &manager, &Manager::complete);
    }

    QObject::connect(&manager, &Manager::getToWork, &marketing,&Marketing::createHype);

    QObject::connect(&marketing, &Marketing::finished, &manager, &Manager::complete);

    manager.startProject();

    return a.exec();
}
