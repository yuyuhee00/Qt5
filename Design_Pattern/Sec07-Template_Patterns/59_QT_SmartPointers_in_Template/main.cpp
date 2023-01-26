/*
 *
    What
    Using Smart pointers with Qt Templated classes

    Description
    Make life easier

    Why
    We take ownership of the memory

    Example
    QSharedPointer

*/

#include <QCoreApplication>
#include <QDebug>
#include <QScopedPointer>
#include <QScopedArrayPointer>
#include <QSharedPointer>
#include <QWeakPointer>
#include "myclass.h"

void addItems(QList<QSharedPointer<MyClass>>& list)
{
     for(int i = 0; i < 10; i++)
     {
         auto myclass = new MyClass(nullptr);
         myclass->setObjectName("MyClass" + QString::number(i));
         list.append(QSharedPointer<MyClass>(myclass));
     }
}

void testList()
{
    QList<QSharedPointer<MyClass>> list;
    addItems(list);
    qInfo() << "Count:" << list.length();
    list.removeAt(2);

    foreach (auto item, list)
    {
        qInfo() << item->objectName();
    }

    qInfo() << "Count:" << list.length();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testList();

    return a.exec();
}
