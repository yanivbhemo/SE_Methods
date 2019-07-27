#include "NumericBox.h"
#include <fstream>

// NumericBox::NumericBox(int minVal, int maxVal) : 
//     Panel(0, 0, 5, 3, new Single, Color::White, Color::Black),
//     inc(Button("+")), 
//     dec(Button("-")), 
//     value(Label(std::to_string(minVal))), 
//     minVal(minVal),
//     maxVal(maxVal)
// {
//     // this->setLeft(this->dec.getLeft());
//     // this->setTop(this->dec.getTop());
//     // this->setWidth(this->inc.getLeft() + 1);
//     this->value.setLeft(this->dec.getValue().length() + 2);
//     this->inc.setLeft(this->value.getValue().length() + 1 + 2);
//     this->inc.addListener(this);
//     this->dec.addListener(this);
//     this->addToPanel(&dec);
//     this->addToPanel(&value);
//     this->addToPanel(&inc);
// }

NumericBox::NumericBox
    (int minVal, int maxVal, short left, short top, short width, short height, Border* border, Color textColor, Color backgroundColor) :
    Panel(left, top, width, height, border, textColor, backgroundColor),
    inc(Button("+")), 
    dec(Button("-")),
    minVal(minVal),
    maxVal(maxVal),
    value(Label(std::to_string(minVal)))
{
    this->val = this->getMinVal();
    this->value.setLeft(this->dec.getValue().length() + 2);
    this->inc.setLeft(this->value.getValue().length() + 1 + 2);
    this->inc.addListener(this);
    this->dec.addListener(this);
    this->addToPanel(&dec);
    this->addToPanel(&value);
    this->addToPanel(&inc);
}

void NumericBox::draw(Graphics& g, int x, int y, size_t z) {
    int controlerX, controlerY;
    if (!z)
        Panel::draw(g, x-1, y-1, z);
}

void NumericBox::activateListener(int x, int y){
    Panel::activateListener(x, y);
}

void NumericBox::mousePressed(int x, int y, bool isLeft){
    // if (isLeft){
    // ofstream myfile;
    // myfile.open ("example.txt");
    // myfile << "Writing this to a file.\n";
    // myfile.close();
    // }
    if (isInside(x,y, this->inc.getLeft(), this->inc.getTop(), this->inc.getWidth(), this->inc.getHeight())){
        this->inc.mousePressed(x, y, isLeft);
        if (val < maxVal)
            val++;
    }
    else if (isInside(x,y, this->dec.getLeft(), this->dec.getTop(), this->dec.getWidth(), this->dec.getHeight())){
        this->dec.mousePressed(x, y, isLeft);
        if (val > minVal)
            val--;
    }
    // value = Label(std::to_string(val));
    // this->draw()
    this->value.setValue(std::to_string(val));
}