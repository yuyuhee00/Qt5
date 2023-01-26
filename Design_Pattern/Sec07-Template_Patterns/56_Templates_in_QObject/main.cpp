/*
 *
    What
    Generics in QObjects

    Description
    Can put generic code in QObject, but can't put a QObject in generic code

    Why
    QObjects should not be copied

    Example
    Fun with templates

 */

#include <QCoreApplication>
#include <QDebug>
#include "myclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyClass myclass;
    qInfo() << myclass.add(2,3);
    qInfo() << myclass.add(6.34, 8.12);

    MyClass m1;
    MyClass m2;

    // again deleted copy constructor
    // MyClass m3 = myclass.add(m1, m2);

    return a.exec();
}
