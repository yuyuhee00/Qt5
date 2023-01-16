#include "light.h"

Light::Light(QObject *parent) : QObject(parent)
{
    m_color = "Uknown";
}

void Light::status()
{
    qInfo() << this << "Color:" << m_color << "Power:" << m_power;
}


void Light::powerOn()
{
    m_power = true;
    status();
}

void Light::powerOff()
{
    m_power = false;
    status();
}

QString Light::color()
{
    return m_color;
}
