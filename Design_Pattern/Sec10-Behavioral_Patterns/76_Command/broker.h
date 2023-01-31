#ifndef BROKER_H
#define BROKER_H

#include <QObject>
#include <QDebug>
#include "interfaces/iOrder.h"

#include <list>

class Broker : public QObject
{
    Q_OBJECT

public:
    explicit Broker(QObject *parent = nullptr);
    ~Broker();

    void addOrder(iOrder* order);
    void placeOrders();

signals:

private:
    QList<iOrder*> m_orders;

    //std::unique_ptr<std::list<iOrder*>> m_orders;
    void cleanup();
};

#endif // BROKER_H
