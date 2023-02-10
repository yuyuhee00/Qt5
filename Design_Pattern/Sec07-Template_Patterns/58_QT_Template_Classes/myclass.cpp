#include "myclass.h"

MyClass::MyClass(QObject *parent) : QObject(parent)
{
    qInfo() << this << "Created";
}

MyClass::~MyClass()
{
    qInfo() << this << "Destroyed";
}
