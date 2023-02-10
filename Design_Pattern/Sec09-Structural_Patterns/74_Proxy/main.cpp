/*

  What
  Flyweight pattern

  Description
  Flyweight allows you to share bulky data that are common to each object.

  Why
  Sometimes you want to save resources

  Example
  Coffee Shop

 */

#include <QCoreApplication>
#include <QDebug>
#include "Person.h"
#include "PettyCash.h"
#include "PettyCashProtected.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PettyCash pc;
    Person workers[4];
    for(int i = 0, amount = 100; i < 4; i++,  amount += 100) {
        if(!pc.widthdraw(workers[i], amount))
            qInfo() << "No moeny for " << workers[i].getName();
        else
            qInfo() << amount << " dollars for" << workers[i].getName();
    }

    qInfo() << "Remaining balance is " << pc.getBalance();

    return a.exec();
}
