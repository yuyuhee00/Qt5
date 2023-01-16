#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <QObject>
#include <QTimer>
#include "lights/redlight.h"
#include "lights/yellowlight.h"
#include "lights/greenlight.h"

class TrafficLight : public QObject
{
    Q_OBJECT

public:
    explicit TrafficLight(QObject *parent = nullptr);
    enum Color { green, yellow, red };
    void start();
    void stop();
    iLight* state();

signals:

private slots:
    void timeout();

private:
    QTimer m_timer;
    Light* m_current;
    int m_count;
    int m_max;
    Color m_color;

    void switchColor(Color newcolor);
};

#endif // TRAFFICLIGHT_H
