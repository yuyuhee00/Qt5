#include "shirt.h"

Shirt::Shirt(QObject *parent) : QObject(parent)
{
    m_value = 0;
}


void Shirt::accept(iVisitor *visitor)
{
    qInfo() << this << "Prepair for a visitor";
    m_value = 55.24; //File IO Maybe

    visitor->visit(this);

    qInfo() << this << "Cleanup after the visitor";
    m_value = 0;
}

double Shirt::amount()
{
    return  m_value;
}
