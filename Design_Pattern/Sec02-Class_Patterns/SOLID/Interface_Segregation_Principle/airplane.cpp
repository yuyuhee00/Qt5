#include "airplane.h"

AirPlane::AirPlane(QObject *parent) : QObject(parent)
{

}


void AirPlane::refuel()
{
    qInfo() << this << "Refueling";
}

void AirPlane::fly()
{
    qInfo() << this << "Flying";
}

void AirPlane::land()
{
    qInfo() << this << "land";
}
