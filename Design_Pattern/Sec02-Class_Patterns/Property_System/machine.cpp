#include "machine.h"

Machine::Machine(QObject *parent) : QObject(parent)
{
    m_count = 0;
    m_max = 100;
    connect(&m_timer, &QTimer::timeout,this, &Machine::timeout);
    m_timer.setInterval(1000);
}

int Machine::count() const
{
    return m_count;
}

void Machine::setCount(int count)
{
    m_count = count;
    emit countChanged(m_count);
}

int Machine::max() const
{
    return m_max;
}

void Machine::setMax(int max)
{
    qInfo() << "Set Max :)";
    m_max = max;
    emit maxChanged(m_max);
}

QString Machine::name() const
{
    return m_name;
}

void Machine::setName(const QString &name)
{
    m_name = name;
}

void Machine::start()
{
    qInfo() << this << "Starting";
    m_timer.start();
    emit started();
}

void Machine::stop()
{
    qInfo() << this << "Stopping";
    m_timer.stop();
    emit stopped();
    setCount(0);
}

void Machine::pause()
{
    qInfo() << this << "Pausing";
    m_timer.stop();
    emit paused();
}

void Machine::timeout()
{
    qInfo()  << this << "Counting...";
    m_count++;
    emit countChanged(m_count);

    if(m_count >= m_max) stop();
}
