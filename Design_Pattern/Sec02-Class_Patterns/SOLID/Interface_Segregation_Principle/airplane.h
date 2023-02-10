#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <QObject>
#include <QDebug>
#include "interfaces/iFlying.h"
#include "interfaces/iMachine.h"

class AirPlane : public QObject, public iFlying, public iMachine
{
    Q_OBJECT
public:
    explicit AirPlane(QObject *parent = nullptr);

signals:


    // iMachine interface
public:
    void refuel() override;

    // iFlying interface
public:
    void fly() override;
    void land() override;
};

#endif // AIRPLANE_H
