#include "Pants.h"

Pants::Pants()
{
    m_value = 0;
}

void Pants::accept(iVisitor *visitor)
{
    qInfo() << this << "Prepair for a visitor";
    m_value = 100.100; //File IO Maybe

    visitor->visit(this);

    qInfo() << this << "Cleanup after the visitor";
    m_value = 0;
}

double Pants::amount()
{
    return  m_value;
}
