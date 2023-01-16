#ifndef BULB_H
#define BULB_H

#include <QObject>
#include <QDebug>

//This class is also part of state (application)
class Bulb : public QObject
{
    Q_OBJECT

public:
    explicit Bulb(QObject *parent = nullptr);

    bool powered() const;
    void setPowered(bool powered);

signals:

private:
    bool m_powered; //Becomes part of the object state (class)
};

#endif // BULB_H
