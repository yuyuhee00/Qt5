#ifndef IDIRECTOR_H
#define IDIRECTOR_H

#include "iBuilder.h"
#include "iMeal.h"

class iDirector
{
public:
    virtual ~iDirector() {}; //we are going to make some people mad... but we need to free the memory

    virtual iMeal* create(iBuilder *builder) = 0;
};

#endif // IDIRECTOR_H
