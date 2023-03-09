/*
 *
    What
    How to use a QObject and a template
    - QObject has members :
        QString objectName() const,
        void setObjectName(QString const&)

    Description
    Pointers / Ref to the rescue!

    Why
    Some people like to live dangerously

    Example
    Can use pointers - but - You could do it better just using QObject

 */

#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include "myclass.h"
#include "notqt.h"


template <class T>
void testQObject(T& x)
{
    if(!std::is_base_of_v<QObject, T>)
    {
        qInfo() << "Not a QObject";
        return;
    }

    x.setObjectName("Hello from template");
}

void testQObjectPtr(QObject *x)
{
    Q_UNUSED(x)
    // No template maddness!!!!
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyClass myclass;
    NotQt nq;

    testQObject(myclass);
    qInfo() << myclass.objectName();

    testQObject(nq);
    qInfo() << nq.objectName();

    return a.exec();
}
