#ifndef IANIMALFACTORY_H
#define IANIMALFACTORY_H

#include "iAnimal.h"

class iAnimalFactory {
public:
    virtual ~iAnimalFactory() {}; //we are going to make some people mad... but we need to free the memory

    virtual iAnimal* createSmall() = 0;
    virtual iAnimal* createMedium() = 0;
    virtual iAnimal* createLarge() = 0;
};

#endif // IANIMALFACTORY_H
