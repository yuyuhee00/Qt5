#ifndef ICLONEABLE_H
#define ICLONEABLE_H

#include <QObject>

class iCloneable
{
public:

    virtual ~iCloneable() {}
    virtual QObject* clone() = 0;
};

#endif // ICLONEABLE_H
