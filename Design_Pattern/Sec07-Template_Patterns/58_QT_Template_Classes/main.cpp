/*
 *
    What
    Qt does use templates for some of its classes
    - Template classes in QT, are not a QObject

    Description
    Special issues using QObjects with Qt templated classes

    Why
    Qt breaks its own rules sometimes

    Example
    QList

 */

#include <QCoreApplication>
#include <QDebug>
#include "myclass.h"

#include <vector>

//void addItem(QList<MyClass*>& list)
//{
//    // QList is not a QObject, so it cannot be a parent of MyClass
//    // It means, QObject's memory management cannot  apply to QList
//    // - Childs of QObject will be removed automatically, if the QObject is removed
//    // Using,   qDeleteAll(list); list.clear();
//   // list.append(new MyClass(list));

//    list.append(new MyClass());
//}

//void removeItem(QList<MyClass*>& list, int index)
//{
//    if(index >= list.length()) return;

//    auto myclass = list.at(index);
//    list.removeAt(index);
//    delete myclass;
//}

//void fillList(QList<MyClass*>& list)
//{
//    for(int i = 0; i < 10; i++)
//    {
//        addItem(list);
//    }
//}

//void printList(QList<MyClass*>& list)
//{
//    foreach(auto myclass, list)
//    {
//        qInfo() << myclass;
//    }
//}


//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    QList<MyClass*> list;
//    addItem(list);

//    fillList(list);

//    qInfo() << list.length();

//    removeItem(list, 0);

//    printList(list);

//    qDeleteAll(list);
//    list.clear();

//    return a.exec();
//}

void addItem(std::vector<std::unique_ptr<MyClass>>& list)
{
    list.push_back(std::make_unique<MyClass>());
}

void removeItem(std::vector<std::unique_ptr<MyClass>>& list, std::size_t index)
{
    if(index < list.size())
    {
        list.erase(list.begin()+index);
    }
}

void fillList(std::vector<std::unique_ptr<MyClass>>& list)
{
    for(int i = 0; i < 20; i++)
    {
        addItem(list);
    }
}

void printList(std::vector<std::unique_ptr<MyClass>>& list)
{
    for(auto iter = list.begin(); iter != list.end();  iter++)
    {
        qInfo() << iter->get();
    }
}

void testList()
{
    std::vector<std::unique_ptr<MyClass>> list;
    addItem(list);

    fillList(list);

    qInfo() << list.size();

    removeItem(list,  0);

    printList(list);

    qInfo() << list.size();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testList();

    return a.exec();
}
