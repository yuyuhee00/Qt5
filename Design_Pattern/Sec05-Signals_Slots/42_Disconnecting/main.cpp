/*

  What
  disconnecting

  Description
  Disconnecting two objects

  Why
  Sometimes we want to stop listening

  Example
  disconnecting

 */

#include <QCoreApplication>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QObject>
#include <QList>
#include "alarm.h"

Alarm* makeAlarm(int seconds, QTimer &timer)
{
    Alarm* alarm = new Alarm();
    alarm->setLimit(QTime::currentTime().addSecs(seconds));
    QObject::connect(&timer, &QTimer::timeout, alarm, &Alarm::timeout);

    return alarm;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTimer timer;
    timer.setInterval(1000);
    timer.start();

    QScopedPointer<Alarm> alarm1(makeAlarm(5, timer));
    alarm1->setObjectName("Alarm1");

    QScopedPointer<Alarm> alarm2(makeAlarm(10, timer));
    alarm2->setObjectName("Alarm2");

    QScopedPointer<Alarm> alarm3(makeAlarm(15, timer));
    alarm3->setObjectName("Alarm3");

    return a.exec();
}
