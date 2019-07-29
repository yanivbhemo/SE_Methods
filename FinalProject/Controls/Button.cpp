#include "Button.h"
#include <fstream>

Button::Button(string value) : Label(value){
    // this->setHeight(3); 
    // this->setWidth(Label::getWidth() + 2);
    // this->setBorder(new Single);
};

void Button::setValue(string value) { this->value = value; };

string Button::getValue() { return this->value; };

void Button::draw(Graphics& g, int x, int y, size_t z) { Label::draw(g, x, y, z); };

void Button::mousePressed(int x, int y, bool isLeft) {
    if (isInside(x, y, x, y, getWidth(), getHeight())) {
        for(int i = 0; i< Listeners.size(); i++){
            Listeners[i]->activateListener(x, y);
        }
    }
}

void Button::addListener(Listener* listener){
    if(listener != nullptr)
        Listeners.push_back(listener);
}

// void Button::setBorder(Border* newBorder){
//     Control::setBorder(newBorder);
// }
