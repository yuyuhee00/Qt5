#include "bulb.h"

Bulb::Bulb(QObject *parent) : QObject(parent)
{
    // inital class state
    m_powered = false;
}

bool Bulb::powered() const
{
    return m_powered;
}

void Bulb::setPowered(bool powered)
{
    //s tate of this object has changed
    m_powered = powered;

    QString message;
    m_powered ? message = "On" : message = "Off";

    qInfo() << this << message;
}
