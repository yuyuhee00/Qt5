#include "producer.h"

Producer::Producer(QObject *parent) : QObject(parent)
{
    m_timer.setInterval(3000);

    // Connect the two objects
    connect(&m_timer, &QTimer::timeout, this, &Producer::produced);
}

void Producer::start()
{
    qInfo() << this << "Producer starting";
    m_timer.start();
}

void Producer::stop()
{
    m_timer.stop();
    qInfo() << this << "Producer stopped";
}

void Producer::produced()
{
    qInfo() << this << "Producing item";
    QSharedPointer<MyClass> ptr(new MyClass());
    emit readyProduct(ptr);
    qInfo() << this << "Item produced";
}
