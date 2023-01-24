#pragma once

#include <QObject>
#include "consumer.h"
#include "producer.h"


inline void ConnectProduerToConsumer(Producer& producer, Consumer& consumer)
{
    QObject::connect(&producer, &Producer::readyProduct, &consumer, &Consumer::readyProduct);

    // QObject::connect(&producer, &Producer::readyProduct2, &consumer, &Consumer::readyProduct2);

    QObject::connect(&producer, &Producer::readyProduct3, &consumer, &Consumer::readyProduct3);
}
