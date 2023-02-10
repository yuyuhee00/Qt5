#pragma once

#include <QDebug>

#include "interfaces/iElement.h"
#include "interfaces/iVisitor.h"

class Pants :  public iElement
{
public:
    Pants();

    // iElement interface
public:
    void accept(iVisitor *visitor) override;
    double amount() override;

private:
    double m_value;
};

