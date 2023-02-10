#ifndef SHORTDELAY_H
#define SHORTDELAY_H

#include <QObject>
#include <QThread>
#include "interfaces/idelay.h"

class ShortDelay : public QObject, public iDelay
{
    Q_OBJECT

public:
    explicit ShortDelay(QObject *parent = nullptr);

    // iDelay interface
public:
    void delay(int ms) override;
    bool isComplete() override;

signals:

private:
    bool m_complete;
};

#endif // SHORTDELAY_H
