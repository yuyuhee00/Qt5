#include "myclass.h"

MyClass::MyClass(QObject *parent, QString name) : QObject(parent)
{
    setObjectName(name);
    qInfo() << this << "Created on" << QThread::currentThread();
}

MyClass::~MyClass()
{
    qInfo() << this << "Destroyed on" << QThread::currentThread();
}

void MyClass::perform()
{
    qInfo() << this << "Emitting signal" << QThread::currentThread();
    emit test();
}

void MyClass::onTest()
{
    qInfo() << this << " ***Test*** from" << sender() << "on" << QThread::currentThread();
}
