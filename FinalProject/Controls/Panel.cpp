#include "Panel.h"
#include <fstream>
#include <iostream>

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
            // if (Controlers[index]->getTop() == 0)
            //     controlerY = Controlers[index]->getTop() + index - 1;
            // else
            controlerY = Controlers[index]->getTop();
            g.setBackground(Controlers[index]->getBackgroundColor());
            g.setForeground(Controlers[index]->getTextColor());
            Controlers[index]->draw(g, controlerX + x + 1, controlerY + y + 1, z);
        }
    }
}

Panel::~Panel(){
    while (!Controlers.empty()){
        Controlers.pop_back();
    }
}

bool Panel::canGetFocus(){
    if (getFocus() != nullptr){
        for (int i = 0; i < Controlers.size(); i++){
            if (Controlers[i] == getFocus())
                return true;
        }
    }
    return false;
}

void Panel::mousePressed(int x, int y, bool isLeft){
    if (canGetFocus())
        getFocus()->mousePressed(x - this->getLeft(), y - this->getTop(), isLeft);
}

void Panel::keyDown(int keyCode, char character){
    if (canGetFocus())
        getFocus()->keyDown(keyCode, character);
}


void Panel::activateListener(int x, int y){
    // ofstream myfile;
    // myfile.open ("example.txt");
    // myfile << "Writing this to a file.\n";
    // myfile.close();
    mousePressed(x, y, true);
}