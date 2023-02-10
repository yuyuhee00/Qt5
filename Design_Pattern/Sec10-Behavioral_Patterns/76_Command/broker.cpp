#include "broker.h"

Broker::Broker(QObject *parent) : QObject(parent)
{
    //m_orders = std::make_unique<std::list<iOrder*>>();
}

Broker::~Broker()
{
    cleanup();
     qInfo() << "Broker Destroyed";
}

void Broker::addOrder(iOrder *order)
{
    qInfo() << this << "Adding order" << order;
    m_orders.append(order);
    //m_orders->push_back(order);
}

void Broker::placeOrders()
{
    foreach (iOrder* order, m_orders)
    {
        qInfo() << this << "Executing order" << order;
        order->execute();
    }

//    for(auto const order : *m_orders)
//    {
//        qInfo() << this << "Executing order" << order;
//        order->execute();
//    }
}

void Broker::cleanup()
{
    qDeleteAll(m_orders);
    m_orders.clear();
}
