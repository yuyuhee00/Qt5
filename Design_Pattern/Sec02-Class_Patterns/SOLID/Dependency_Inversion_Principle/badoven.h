#ifndef BADOVEN_H
#define BADOVEN_H

#include <QObject>
#include <QDebug>
#include "basicoven.h"
#include "interfaces/iEvenHeat.h"

class BadOven : public BasicOven, public iEvenHeat
{
    Q_OBJECT
public:
    explicit BadOven(QObject *parent = nullptr);

signals:


    // iOven interface
public:
    void bake() override;

    // iEvenHeat interface
public:
    void flip() override;
    void rotate() override;
};

#endif // BADOVEN_H
