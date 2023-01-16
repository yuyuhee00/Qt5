#include "myclass.h"

MyClass::MyClass(QObject *parent) : QObject(parent)
{
    m_firstname = "Firstname";
    m_lastname = "Lastname";
    m_age = 0;
}

QString MyClass::firstname() const
{
    return m_firstname;
}

void MyClass::setFirstname(const QString &firstname)
{
    m_firstname = firstname;
}

QString MyClass::lastname() const
{
    return m_lastname;
}

void MyClass::setLastname(const QString &lastname)
{
    m_lastname = lastname;
}

int MyClass::age() const
{
    return m_age;
}

void MyClass::setAge(int age)
{
    m_age = age;
}

void MyClass::display()
{
    qInfo() << this << firstname() << lastname() << age();
}


QObject *MyClass::clone()
{
    MyClass *myclass = new MyClass(this->parent());
    myclass->setAge(age());
    myclass->setFirstname(firstname());
    myclass->setLastname(lastname());

    return myclass;
}
