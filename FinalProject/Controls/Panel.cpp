#include "Panel.h"

Panel::Panel(){
    Control();
}

Panel::Panel(short left, short top, short width, short height, Border* border, Color textColor, Color backgroundColor) {
    Control(left, top, width, height, border, textColor, backgroundColor);
}

void Panel::addToPanel(Control* controler){
    if (controler != nullptr)
        Controlers.push_back(controler);
}

void Panel::draw(Graphics& g, int x, int y, size_t z){
    int controlerX, controlerY;
    if (!z){
        Control::draw(g, x, y, z);
        for (int index = 0; Controlers.size() > index; index++){
            controlerX = Controlers[index]->getLeft();
            controlerY = Controlers[index]->getTop();
            g.setBackground(Controlers[index]->getBackgroundColor());
            g.setForeground(Controlers[index]->getTextColor());
            Controlers[index]->draw(g,controlerX + x + 2, controlerY + y + 2, z);
        }
    }
}

Panel::~Panel(){
    while (!Controlers.empty()){
        Controlers.pop_back();
    }
}