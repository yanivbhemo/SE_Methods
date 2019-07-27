#include "Control.h"
#include <fstream>

Control* Control::focused = nullptr;

Control::Control() : left(0), top(0), width(0), height(0), textColor(Color::White), backgroundColor(Color::Black), border(new None) {};

Control::Control(short left, short top, short width, short height, Border* border, Color textColor, Color backgroundColor){
    this->left = left;
    this->top = top;
    this->width = width;
    this->height = height;
    this->border = border;
    this->textColor = textColor;
    this->backgroundColor = backgroundColor;
    visible = true;
}

Control::~Control(){
    if(border)
        delete border;
}

void Control::setBorder(Border* newBorder) {
    if (this->border)
        delete this->border;
    this->border = newBorder;
}


void Control::setFocus(Control& control){
    if (focused == nullptr)
        control.setFocus(control);
    if ((focused != &control) && (control.canGetFocus())){
        /* if (focused) */
        focused->setFocus(control);
        // else {
        //     focused = &control;
        //     focused->focus();
        // }
    }
}


// void Control::setFocus(Control& control){
//     if (focused != &control)
//         focused = &control;
// }

void Control::draw(Graphics& g, int x, int y, size_t z){
    g.setForeground(getTextColor());
    g.setBackground(getBackgroundColor());
    border->drawBorder(g, left, top, width, height);
}
