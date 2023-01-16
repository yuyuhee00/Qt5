#include "bulb.h"

Bulb::Bulb(QObject *parent) : QObject(parent)
{
    m_powered = false; //inital class state
}

bool Bulb::powered() const
{
    return m_powered;
}

void Bulb::setPowered(bool powered)
{
    m_powered = powered; //state of this object has changed

    QString message;
    m_powered ? message = "On" : message = "Off";

    qInfo() << this << message;
}
