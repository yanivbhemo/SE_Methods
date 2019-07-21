#include "Control.h"

Control* Control::focused = nullptr;

Control::Control()
{
    left = 0;
    top = 0;
    width = 1;
    height = 1;
    border = new Border;
    textColor = Color::White;
    backgroundColor = Color::Black;
    visible = true;
}

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

Control::~Control(){}


// void Control::setFocus(Control& control){
//     if ((focused != &control) && (control.canGetFocus())){
//         if (focused) focused->unFocus();
//         else {
//             focused = &control;
//             focused->focus();
//         }
//     }
// }


void Control::draw(Graphics& g, int x, int y, size_t z){
    g.setForeground(getTextColor());
    g.setBackground(getBackgroundColor());
    border->drawBorder(g, left, top, width + 3, height + 3);
}
