#include <QCoreApplication>

/*

  What
  Prototype design pattern

  Description
  Create new objects by copying the original
  - Specify the kinds of objects to create using a prototypical instance, and create
    new object by copying this prototype

  Why
  Start with a uniform complex object

  Example
  https://sourcemaking.com/design_patterns/prototype

  Remember - QObjects don't like to be copied!
  https://www.cleanqt.io/blog/why-qobject-subclasses-are-not-copyable

 */

#include "myclass.h"

//This will fail and we can not get past the copy constructor being removed
//MyClass willFail()
//{
//    MyClass myclass;
//    return myclass;
//}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Prototype
    MyClass bryan;
    bryan.setAge(45);
    bryan.setFirstname("Bryan");
    bryan.setLastname("Cairns");

    MyClass *heather  = qobject_cast<MyClass*>(bryan.clone());
    heather->setFirstname("Heather");
    heather->setAge(28);

    MyClass *tammy  = qobject_cast<MyClass*>(bryan.clone());
    tammy->setFirstname("Tammy");
    tammy->setAge(49);

    bryan.display();
    heather->display();
    tammy->display();

    return a.exec();
}
