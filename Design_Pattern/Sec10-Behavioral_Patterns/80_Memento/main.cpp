#include <QCoreApplication>

/*

  What
  Memento design pattern

  Description
  Without violating encapsulation, capture and externalize an object's internal state so that the object can be returned to this state later.

  Why
  The Memento captures and externalizes an object's internal state so that the object can later be restored to that state

  Example
  Transactions


 */

#include <QDebug>
#include "memento.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Memento controller;
    controller.addTransaction("Hello");
    controller.addTransaction("World");
    controller.commit();

    controller.addTransaction("Stuff here");
    controller.addTransaction("bla bla bla bla");
   // controller.commit();
    controller.rollback();

    qInfo() << "TSs : " << controller.command();

    return a.exec();
}
