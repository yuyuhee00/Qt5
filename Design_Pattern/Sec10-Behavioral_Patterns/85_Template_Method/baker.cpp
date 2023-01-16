#include "baker.h"

Baker::Baker(QObject *parent) : Chef(parent)
{

}


void Baker::prepair()
{
    qInfo() << "mix the cake ingredients";
}

void Baker::cook()
{
    qInfo() << "preheat the oven";
    qInfo() << "bake the cake";
    qInfo() << "let it cool";
    qInfo() << "EXTRA frosting!!!!";
}

void Baker::cleanup()
{
    qInfo() << "Make the kids cleanup";
}
