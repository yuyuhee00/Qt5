#ifndef CONSUMER_H
#define CONSUMER_H

#include <QObject>
#include <QDebug>
#include <QSharedPointer>
#include <QTime>
#include "myclass.h"

class Consumer : public QObject
{
    Q_OBJECT

public:
    explicit Consumer(QObject *parent = nullptr);

signals:

public slots:
    void readyProduct(QSharedPointer<MyClass> ptr);

    // void readyProduct2(std::unique_ptr<MyClass> ptr);
    void readyProduct3(std::shared_ptr<MyClass> ptr);
};

#endif // CONSUMER_H
