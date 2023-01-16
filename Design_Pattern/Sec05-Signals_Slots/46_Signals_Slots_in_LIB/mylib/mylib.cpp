#include "mylib.h"

Mylib::Mylib(QObject *parent) : QObject(parent)
{
    m_timer.setInterval(1000);
    connect(&m_timer, &QTimer::timeout, this, &Mylib::timeout);
}

void Mylib::start()
{
    m_timer.start();
    emit started();
}

void Mylib::stop()
{
    m_timer.stop();
    emit stopped();
}

void Mylib::timeout()
{
    emit triggered(QTime::currentTime().toString());
}
