#include "advancedoven.h"

AdvancedOven::AdvancedOven(QObject *parent) : QObject(parent)
{

}


void AdvancedOven::bake()
{
    qInfo() << this << "do advanced stuff";
    flip();
    rotate();
    qInfo() << this << "bake";
}

void AdvancedOven::flip()
{
    qInfo() << this << "flip the food";
}

void AdvancedOven::rotate()
{
    qInfo() << this << "rotate";
}
