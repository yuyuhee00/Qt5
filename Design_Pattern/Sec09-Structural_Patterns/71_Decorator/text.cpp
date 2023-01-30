#include "text.h"

Text::Text(QObject *parent) : QObject(parent)
{

}

void Text::process(QString &input)
{
    if(this->parent())
    {
        Text *text= qobject_cast<Text*>(this->parent());
        if(text) text->process(input);
    }
}
