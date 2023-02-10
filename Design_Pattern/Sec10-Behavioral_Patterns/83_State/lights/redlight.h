#ifndef REDLIGHT_H
#define REDLIGHT_H

#include <QObject>
#include "light.h"

class RedLight : public Light
{
    Q_OBJECT

public:
    explicit RedLight(QObject *parent = nullptr);

signals:

};

#endif // REDLIGHT_H
