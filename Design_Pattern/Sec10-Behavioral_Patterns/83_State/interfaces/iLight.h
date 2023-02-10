#ifndef ILIGHT_H
#define ILIGHT_H

#include <QString>

class iLight {
public:
    virtual ~iLight() {} //we are going to make some people mad... but we need to free the memory

    virtual void powerOn() = 0;
    virtual void powerOff() = 0;
    virtual QString color() = 0;
};

#endif // ILIGHT_H
