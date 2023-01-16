#ifndef ADVANCEDOVEN_H
#define ADVANCEDOVEN_H

#include <QObject>
#include <QDebug>
#include "interfaces/iOven.h"
#include "interfaces/iEvenHeat.h"

class AdvancedOven : public QObject, public iEvenHeat, public iOven
{
    Q_OBJECT
public:
    explicit AdvancedOven(QObject *parent = nullptr);

signals:


    // iOven interface
public:
    void bake() override;

    // iEvenHeat interface
public:
    void flip() override;
    void rotate() override;
};

#endif // ADVANCEDOVEN_H
