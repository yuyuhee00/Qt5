/*

  What
  Strategy Design Pattern

  Description
  Define a family of algorithms, encapsulate each one, and make them interchangeable.
  - Capture the abstraction in an interface, bury implementation details in derived classes.

  Why
  Easy to swap out functionality

  Example
  Interfaces make this incredibly simple

 */

#include <QCoreApplication>
#include <QDebug>
#include <QRandomGenerator>
#include "interfaces/iWorker.h"
#include "workers/construction.h"
#include "workers/office.h"
#include "workers/surgen.h"

void fillList(QList<iWorker*> &list)
{
    for(int i = 0; i < 100; i++)
    {
        int value = QRandomGenerator::global()->bounded(3);
        switch (value) {
        case 0:
            list.append(new Construction());
            break;
        case 1:
            list.append(new Office());
            break;
        case 2:
            list.append(new Surgen());
            break;
        default:
            list.append(new Construction());
            break;
        }
    }
}

void performWork(QList<iWorker*> &list)
{
    foreach (auto worker, list)
    {
        worker->work();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<iWorker*> list;

    fillList(list);
    performWork(list);

    qDeleteAll(list);
    list.clear();

    return a.exec();
}
