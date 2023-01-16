#include "notqt.h"

NotQt::NotQt()
{

}

void NotQt::setObjectName(QString name)
{
    m_objectname = name;
}

QString NotQt::objectName()
{
    return m_objectname;
}
