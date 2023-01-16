#include <QCoreApplication>

/*
    What
    Using generics

    Description
    Generics can be implemented in C++ using Templates.

    Why
    Makes life easier and code reuse

    Example
    Basic generics
    QObjects typically don't work with generics as QObjects are not copyable
 */

#include <QDebug>
#include "myclass.h"

template <typename T>
T add(T x, T y)
{
    return x + y;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int valueInt = add(3,6);
    qInfo() << "Int: " << valueInt;

    double valueDouble = add(3.54,6.98);
    qInfo() << "Double: " << valueDouble;

    QString valueString = add(QString("Hello"), QString("World"));
    qInfo() << "String: " << valueString;

    MyClass m1;
    MyClass m2;

    m1.setValue(3);
    m2.setValue(5);

    // Will not workwaaA
    // MyClass m3 = add(m1, m2);

    MyClass m3;
    m3.setValue(add(m1.value(), m2.value()));

    qInfo() << "MyClass: " << m3.value();

    return a.exec();
}
