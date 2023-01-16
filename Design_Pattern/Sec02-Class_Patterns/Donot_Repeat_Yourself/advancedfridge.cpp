#include "advancedfridge.h"

AdvancedFridge::AdvancedFridge(QObject *parent) : BasicFridge(parent)
{

}

void AdvancedFridge::deepFreeze()
{
    qInfo() << this << "Putting food into a deep freeze";
}

iRadio *AdvancedFridge::radio() const
{
    return m_radio;
}

void AdvancedFridge::setRadio(iRadio *radio)
{
    m_radio = radio;
}
