#include "NumericBox.h"

NumericBox::NumericBox
    (int minVal, int maxVal, short left, short top, short width, short height, Border* border, Color textColor, Color backgroundColor) :
    Panel(left, top, width, height, border, textColor, backgroundColor),
    inc(Button("+")), 
    dec(Button("-")),
    minVal(minVal),
    maxVal(maxVal),
    value(Label(std::to_string(minVal))) {
        val = this->getMinVal();
        value.setLeft(this->dec.getValue().length() + 2);
        inc.setLeft(to_string(maxVal).length() + 1 + 2);
        this->setWidth(inc.getLeft() + 1);
        this->inc.addListener(this);
        this->dec.addListener(this);
        this->addToPanel(&dec);
        this->addToPanel(&value);
        this->addToPanel(&inc);
}

void NumericBox::draw(Graphics& g, int x, int y, size_t z) {
    if (!z)
        Panel::draw(g, x-1, y-1, z);
}

void NumericBox::activateListener(int x, int y){   
    if ((getLeft() + inc.getLeft() + 1 == x) && (getTop() + inc.getTop() + 1 == y)) {
        if (val < maxVal){
            value.setValue(std::to_string(++val));
        }    
    }
    else if ((getLeft() + dec.getLeft() + 1 == x) && (getTop() + dec.getTop() + 1 == y)) {
        if (val > minVal) {
            value.setValue(std::to_string(--val));
        }
    }
}

void NumericBox::mousePressed(int x, int y, bool isLeft){
    if (!Control::lockEvent){
        if (isInside(x,y, getLeft() + inc.getLeft() + 1, getTop() + inc.getTop() + 1, getWidth() + inc.getWidth(), getHeight() + inc.getHeight())){
            inc.mousePressed(x, y, isLeft);
        }
        else if (isInside(x,y, getLeft() + dec.getLeft() + 1, getTop() + dec.getTop() + 1, getWidth() + dec.getWidth(), getHeight() + dec.getHeight())){
            dec.mousePressed(x, y, isLeft);
        }
    }
}