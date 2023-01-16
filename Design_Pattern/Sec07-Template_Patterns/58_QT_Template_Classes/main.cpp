#include <QCoreApplication>

/*
    What
    Qt does use templates for some of its classes

    Description
    Special issues using QObjects with Qt templated classes

    Why
    Qt breaks its own rules sometimes

    Example
    QList

 */

#include <QDebug>
#include "myclass.h"

void addItem(QList<MyClass*> &list)
{
    list.append(new MyClass());
}

void fillList(QList<MyClass*> &list)
{
    for(int i = 0; i < 10; i++)
    {
        addItem(list);
    }
}

void removeItem(QList<MyClass*> &list, int index)
{
    if(index >= list.length()) return;

    auto myclass = list.at(index);
    list.removeAt(index);
    delete myclass;
}

void printList(QList<MyClass*> &list)
{
    foreach(auto myclass, list)
    {
        qInfo() << myclass;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<MyClass*> list;
    addItem(list);

    fillList(list);

    qInfo() << list.length();

    removeItem(list, 0);

    printList(list);

    qDeleteAll(list);

    return a.exec();
}
