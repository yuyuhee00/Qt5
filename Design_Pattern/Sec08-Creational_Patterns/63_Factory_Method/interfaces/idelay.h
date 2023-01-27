#ifndef IDELAY_H
#define IDELAY_H

#include <QObject>

class iDelay
{
public:
    virtual ~iDelay() {} //This will annoy people

    virtual void delay(int ms) = 0;
    virtual bool isComplete() = 0;
};

#endif // IDELAY_H
