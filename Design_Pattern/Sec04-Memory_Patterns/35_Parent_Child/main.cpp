/*

  What
  Parent child memory managment - aka the Qt way

  Description
  Setting a QObjects parent, so when the parent is deleted, all the children are deleted

  Why
  Super easy memory managment

  Example
  Parent and children
QObjects organize themselves in object trees.
When you create a QObject with another object as parent, the object will automatically add itself to the parent's children() list.
The parent takes ownership of the object; i.e., it will automatically delete its children in its destructor.
You can look for an object by name and optionally type using findChild() or findChildren().

 */

#include <QCoreApplication>
#include <QDebug>
#include "myclass.h"

void createHierichyChildren(MyClass *parent, int count)
{
    if(!parent) return;
    qInfo() << "Creating Hierachy children";

    MyClass* prev = nullptr;
    for(int i = 0; i < count; i++)
    {
        // Heap
        if(prev == nullptr) {
           prev = parent;
         }
         MyClass* child = new MyClass(prev);
         child->setObjectName("Child " + QString::number(i));
         prev = child;
    }
}

void createChildren(MyClass *parent, int count)
{
    if(!parent) return;
    qInfo() << "Creating children";

    for(int i = 0; i < count; i++)
    {
        // Heap
        MyClass *child = new MyClass(parent);
        child->setObjectName("Child " + QString::number(i));
    }
}

void listChild(MyClass *parent)
{
    if(!parent) return;
    qInfo() << "Listing children";

    foreach(QObject *obj, parent->children())
    {
        MyClass *child = qobject_cast<MyClass*>(obj);

        // test child
        qInfo() << "Child: " << child;
    }
}

void findChild(MyClass* parent, QString name)
{
    if(!parent) return;
    qInfo() << "Find child";

    QList<QObject*> list = parent->findChildren<QObject*>(name);
    qInfo() << "Found " << list.length();

    foreach(QObject *obj, list)
    {
        MyClass *child = qobject_cast<MyClass*>(obj);

        // test child
        qInfo() << "Found: " << child->objectName();
    }
}

void testQt()
{
    // Stack
    MyClass parent(nullptr);
    parent.setObjectName("parent");

    // createChildren(&parent, 5);
    createHierichyChildren(&parent, 5);

    listChild(&parent);
    findChild(&parent, "Child 2");
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testQt();

    return a.exec();
}
