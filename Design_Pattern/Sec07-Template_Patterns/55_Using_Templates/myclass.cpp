#include "myclass.h"

MyClass::MyClass(QObject *parent) : QObject(parent)
{
    qInfo() << this << "Created";
}

MyClass::~MyClass()
{
    qInfo() << this << "Destroyed";
}

int MyClass::value() const
{
    return m_value;
}

void MyClass::setValue(int value)
{
    m_value = value;
}
