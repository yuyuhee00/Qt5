#ifndef LIGHT_H
#define LIGHT_H

#include <QObject>
#include <QDebug>

#include "../interfaces/iLight.h"

class Light : public QObject, public iLight
{
    Q_OBJECT

public:
    explicit Light(QObject *parent = nullptr);

    void status();

signals:

    // iLight interface
public:
    void powerOn() override;
    void powerOff() override;
    QString color() override;

protected:
    QString m_color;
    bool m_power;
};

#endif // LIGHT_H
