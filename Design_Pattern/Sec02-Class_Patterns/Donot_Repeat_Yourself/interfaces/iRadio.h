#ifndef IRADIO_H
#define IRADIO_H

class iRadio
{
public:
    virtual ~iRadio(){};

    virtual void play() = 0;
    virtual void stop() = 0;
};

#endif // IRADIO_H
