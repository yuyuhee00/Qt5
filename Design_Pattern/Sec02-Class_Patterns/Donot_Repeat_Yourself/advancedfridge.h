#ifndef ADVANCEDFRIDGE_H
#define ADVANCEDFRIDGE_H

/*
  Hybred object with both interfaces and inheritance

  Vendor makes an advanced fridge and decides to put a radio in it
  Why make a new basic radio, when you can simply put the existing radio into the fridge

 */

#include <QObject>
#include <QDebug>
#include "basicfridge.h"
#include "interfaces/iRadio.h"

class AdvancedFridge : public BasicFridge
{
    Q_OBJECT
public:
    explicit AdvancedFridge(QObject *parent = nullptr);

    void deepFreeze();

    iRadio *radio() const;
    void setRadio(iRadio *radio);

signals:

private:
    iRadio *m_radio;

};

#endif // ADVANCEDFRIDGE_H
