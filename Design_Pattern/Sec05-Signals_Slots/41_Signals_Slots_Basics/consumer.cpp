#include "consumer.h"

Consumer::Consumer(QObject *parent) : QObject(parent)
{

}

void Consumer::readyProduct(QSharedPointer<MyClass> ptr)
{
    qInfo() << this << "Consumer is working";

    ptr->test(QTime::currentTime().toString());

    qInfo() << this << "Consumer has finished";
}

//void Consumer::readyProduct2(std::unique_ptr<MyClass> ptr)
//{
//    qInfo() << this << "Consumer 2 is working";

//    ptr->test(QTime::currentTime().toString());

//    qInfo() << this << "Consumer 2 has finished";
//}

void Consumer::readyProduct3(std::shared_ptr<MyClass> ptr)
{
    qInfo() << this << "Consumer 3 is working";

    ptr->test(QTime::currentTime().toString());

    qInfo() << this << "Consumer 3 has finished";
}
