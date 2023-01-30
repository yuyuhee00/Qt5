#ifndef IHOTEL_H
#define IHOTEL_H

class iHotel
{
public:
    virtual ~iHotel() {}
    virtual void bookRoom() = 0;
};

#endif // IHOTEL_H
