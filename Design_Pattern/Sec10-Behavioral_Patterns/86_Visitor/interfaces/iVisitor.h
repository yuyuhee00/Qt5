#ifndef IVISITOR_H
#define IVISITOR_H

class iElement;
#include "iElement.h"

//For example a shopping cart
class iVisitor
{
public:
    virtual ~iVisitor() {} //this will make people mad

    virtual void visit(iElement* element) = 0;
};



#endif // IVISITOR_H
