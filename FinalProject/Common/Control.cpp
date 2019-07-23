#include "Control.h"
#include <fstream>

Control* Control::focused = nullptr;

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


void Control::setFocus(Control& control){
    if ((focused != &control) && (control.canGetFocus())){
        if (focused) focused->unFocus();
        else {
            focused = &control;
            focused->focus();
        }
    }
}


void Control::draw(Graphics& g, int x, int y, size_t z){
    g.setForeground(getTextColor());
    g.setBackground(getBackgroundColor());
    ofstream myfile;
    myfile.open ("example2.txt");
    myfile << width << endl << height << endl << left << endl << top << endl;
    myfile.close();
    border->drawBorder(g, left, top, width, height);
}
