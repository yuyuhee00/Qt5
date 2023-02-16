/*

  What
  Proxy pattern

  Description
  Proxy provides a substitute or placeholder for another bject.
  - A proxy controls access to the original object, alowing you to perform something either before or after
    the request gets through to the original object.

  Why

  Example

 */

#include <QCoreApplication>
#include <QDebug>
#include "Person.h"
#include "PettyCashProxy.h"
//#include "PettyCash.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PettyCashProxy proxy;
    Person workers[4];
    for(int i = 0, amount = 100; i < 4; i++,  amount += 100) {
        if(!proxy.widthdraw(workers[i], amount))
            qInfo() << "No moeny for " << workers[i].getName();
        else
            qInfo() << amount << " dollars for" << workers[i].getName();
    }

    qInfo() << "Remaining balance is " << proxy.getBalance();

    return a.exec();
}
