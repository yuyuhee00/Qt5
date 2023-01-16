#ifndef YELLOWLIGHT_H
#define YELLOWLIGHT_H

#include <QObject>
#include "light.h"

class YellowLight : public Light
{
    Q_OBJECT

public:
    explicit YellowLight(QObject *parent = nullptr);

signals:

};

#endif // YELLOWLIGHT_H
