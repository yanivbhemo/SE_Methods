#pragma once
#include "../Common/Control.h"
#include "vector"

class Panel : public Control{
    protected:
        vector <Control*> Controlers;
        int focusedControlCell;

    public:
        Panel(short left, short top, short width, short height, Border* border, Color textColor, Color backgroundColor) : Control(left, top, width, height, border, textColor, backgroundColor) {};
        ~Panel();
        
        void addToPanel(Control* controler);
        void draw(Graphics& g, int x, int y, size_t z);
        virtual void keyDown(int keyCode, char character);
        virtual void mousePressed(int x, int y, bool isLeft);
        int findFocusIndex();
        void updateFocusedControler(Control* controler);
        
        int getFocusedControlCell(){ return focusedControlCell; }

        void getAllControls(vector<Control*>* controls);
};
