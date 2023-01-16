#include "alarm.h"

Alarm::Alarm(QObject *parent) : QObject(parent)
{
    qInfo() << this << "Constructed";
}

Alarm::~Alarm()
{
    qInfo() << this << "Destroyed";
}

QTime Alarm::limit() const
{
    return m_limit;
}

void Alarm::setLimit(const QTime &limit)
{
    m_limit = limit;
    qInfo() << this << "Alarm set for" << m_limit;
}

void Alarm::timeout()
{
    //qInfo() << this << "Timeout";
    QTimer *timer = qobject_cast<QTimer*>(sender());
    if(!timer) return;

    if(QTime::currentTime() >= m_limit)
    {
        //Sound the alarm
        qInfo() << this << "Alarm";

        disconnect(timer, &QTimer::timeout, this, &Alarm::timeout);
    }
}
