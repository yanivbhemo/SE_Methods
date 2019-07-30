#include "Panel.h"
#include <fstream>
#include <iostream>

void Panel::updateFocusedControler(Control* controler){
    if(getFocus() == nullptr && controler->canGetFocus()){
        setFocus(*controler);
    }
}

void Panel::addToPanel(Control* controler){
    if (controler != nullptr)
        Controlers.push_back(controler);
        try{
            updateFocusedControler(controler); 
        }
        catch(...){}
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
            // Controlers[index]->draw(g, controlerX + x, controlerY + y, z);
        }
    }
}

Panel::~Panel(){
    while (!Controlers.empty()){
        Controlers.pop_back();
    }
}

int Panel::findFocusIndex(){
    ofstream myfile;
    myfile.open ("findFocusIndex.txt", std::ios_base::app);
    
    Control* tempFocus = getFocus();
    if (getFocus() != nullptr){
        for (int i = 0; i < Controlers.size(); i++){
            if (Controlers[i] == tempFocus){
                focusedControlCell = i;
                myfile << "focusedControlCell " << i << endl;
                return i;
            }
            else if(Controlers[i]->findFocusIndex() != -1){
                focusedControlCell = i;
                myfile << "focusedControlCell " << i << endl;
                return i;
            }
        }
    }
    focusedControlCell = -1;
    myfile.close();
    return -1;
}

void Panel::mousePressed(int x, int y, bool isLeft){    
    ofstream myfile;
    myfile.open ("example1.txt", std::ios_base::app);
    myfile << x << " " << y << endl;
    myfile << focusedControlCell << endl;
    myfile.close();

    if(isInside(x,y, getLeft(), getTop(), getWidth(), getHeight())) {
        if (findFocusIndex() != -1) {
            Controlers[focusedControlCell]->mousePressed(x, y, isLeft);
        }
    }    
}

void Panel::keyDown(int keyCode, char character){
    if (findFocusIndex() != -1)
        Controlers[focusedControlCell]->keyDown(keyCode, character);
}