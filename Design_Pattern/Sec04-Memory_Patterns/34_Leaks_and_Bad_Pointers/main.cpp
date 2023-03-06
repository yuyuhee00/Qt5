/*

  What
  Memory leaks, stale pointers

  Description
  When we use a pointer, we are required to manage that memory

  Why
  its what makes C++ both powerfull and dangerous

  Examples
  Memory leak

 */

#include <QCoreApplication>
#include <QList>
#include <QDebug>
#include "myclass.h"

void fillList(QList<MyClass*> &list, int max)
{
    for(int i = 0 ; i < max; i++)
    {
        MyClass *myclass = new MyClass(); //We created, we OWN it
        myclass->setObjectName("Object " + QString::number(i));
        list.append(myclass);
    }
}

void demoLeak()
{
    qInfo() << "Making a leak";
    QList<MyClass*> list;
    fillList(list, 5);

    list.clear();

    // None of the pointers have been deleted!!!
}

void demoDanglingPointer()
{
    qInfo() << "Making a dangling pointers";
    QList<MyClass*> list;
    fillList(list, 5);

    // Delete some memory
    // - memory is gone!
    delete list.at(2);

    /*
    MyClass* tmp = list.at(2);
    list.removeAt(2);
    delete tmp;
    */

    qInfo() << list.length();

    foreach(MyClass *item, list)
    {
        qInfo() << item->objectName();
    }
}

void demoCorrect()
{
    qInfo() << "Making a pointers";
    QList<MyClass*> list;
    fillList(list, 5);

    // Deletes the memory
    qDeleteAll(list);

    // Removes the dangling pointers
    list.clear();

    qInfo() << list.length();

    foreach(MyClass *item, list)
    {
        qInfo() << item->objectName();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//     demoLeak();

//    demoDanglingPointer();

    demoCorrect();

    return a.exec();
}
