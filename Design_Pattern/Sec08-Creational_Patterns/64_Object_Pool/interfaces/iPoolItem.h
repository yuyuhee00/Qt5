#ifndef IPOOLITEM_H
#define IPOOLITEM_H

class iPoolItem
{
public:
    virtual ~iPoolItem() {}

    virtual void reset() = 0;
    virtual bool aquired() = 0;
};

#endif // IPOOLITEM_H
