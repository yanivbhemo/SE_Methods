#include "Label.h"
#include <iostream>

Label::Label(string value) : Control(), value(value) {
    this->setWidth(value.length() + 1);
}; 

string Label::getValue()
{
    return this->value;
}

void Label::setValue(string value)
{
    this->value = value;
}


void Label::draw(Graphics& g, int x, int y, size_t z)
{
    if (!z){
        g.moveTo(x, y);
        g.write(value);
    }
}
