#include "trafficlight.h"

TrafficLight::TrafficLight(QObject *parent) : QObject(parent)
{
    m_current = nullptr;
    m_count = 0;
    m_max = 4;
    m_color = Color::green;
    m_timer.setInterval(1000);
    connect(&m_timer, &QTimer::timeout, this, &TrafficLight::timeout);
}

void TrafficLight::start()
{
    switchColor(Color::green);
    m_timer.start();
}

void TrafficLight::stop()
{
    if(!m_current) return;
    m_timer.stop();
    m_current->powerOff();
    delete m_current;
    m_current = nullptr;

}

iLight *TrafficLight::state()
{
    return  m_current; //Notice this is an interface
}

void TrafficLight::timeout()
{
    if(m_count >= m_max)
    {
        switch (m_color) {
        case Color::green:
            switchColor(Color::yellow);
            break;
        case Color::yellow:
            switchColor(Color::red);
            break;
        case Color::red:
            switchColor(Color::green);
            break;
        }
    }
    m_count++;
}

void TrafficLight::switchColor(TrafficLight::Color newcolor)
{
    //This is where we are changing the state
    if(m_current)
    {
        m_current->powerOff();
        delete m_current;
    }

    m_color = newcolor;

    if(m_color == Color::green) m_current = new GreenLight(this);
    if(m_color == Color::yellow) m_current = new YellowLight(this);
    if(m_color == Color::red) m_current = new RedLight(this);

    m_current->powerOn();
    m_count = 0;
    qInfo() << m_current;
}
