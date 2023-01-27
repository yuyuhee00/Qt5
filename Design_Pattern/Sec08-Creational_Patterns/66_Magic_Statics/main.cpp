/*

  What
  Singleton pattern or C++11 Magic Static

  Description
  Only one instance of the class

  Why
  Sometimes you want to limit the code to once intance

  Example
  Timer

  Note singletons are considered bad practice and can have issues with threads!
  A much better way of creating a singleton is to rely on C++11 Magic Statics  And simply do this:

  https://codereview.stackexchange.com/questions/173929/modern-c-singleton-template
  http://www.nuonsoft.com/blog/2017/08/10/implementing-a-thread-safe-singleton-with-c11-using-magic-statics/
 */

#include <QCoreApplication>
#include "myclass.h"
#include "singleton.h"
#include <QDebug>

void scopetest()
{
    Singleton<MyClass>::GetInstance().setObjectName("Godzilla!");
    Singleton<MyClass>::GetInstance().display("from scope test");
}

void looptest()
{
    Singleton<MyClass>::GetInstance().display("starting loop");

    for(int i = 0; i < 10; i++)
    {
        Singleton<MyClass>::GetInstance().display(QString::number(i));
    }

    Singleton<MyClass>::GetInstance().display("finished loop");

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    scopetest();
    looptest();

    Singleton<MyClass>::GetInstance().display("hello from main");
    qInfo() << Singleton<MyClass>::GetInstance().objectName();

    return a.exec();
}
