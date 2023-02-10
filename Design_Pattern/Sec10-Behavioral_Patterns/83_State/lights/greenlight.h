#ifndef GREENLIGHT_H
#define GREENLIGHT_H

#include <QObject>
#include "light.h"

class GreenLight : public Light
{
    Q_OBJECT

public:
    explicit GreenLight(QObject *parent = nullptr);

signals:

};

#endif // GREENLIGHT_H
