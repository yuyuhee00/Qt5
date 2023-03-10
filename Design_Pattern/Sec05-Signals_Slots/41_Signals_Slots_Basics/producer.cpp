#include "producer.h"

Producer::Producer(QObject *parent) : QObject(parent)
{
    m_timer.setInterval(3000);

    connect(&m_timer, &QTimer::timeout, this, &Producer::produced);
}

Producer::~Producer()
{
    qInfo() << this << "Producer Destroyed";
}
void Producer::start()
{
    qInfo() << this << "Producer starting";
    m_timer.start();
}

void Producer::stop()
{
    qInfo() << this << "Producer stopped";
    m_timer.stop();
}

void Producer::produced()
{
    qInfo() << this << "Producing item";

    QSharedPointer<MyClass> ptr(new MyClass());
    emit readyProduct(ptr);

//    std::unique_ptr<MyClass> ptr2(new MyClass);
//    emit readyProduct2(std::move(ptr2));

    std::shared_ptr<MyClass> ptr3(new MyClass);
    emit readyProduct3(ptr3);

    qInfo() << this << "Item produced";
}
