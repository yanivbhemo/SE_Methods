#pragma once
#include "../Common/Control.h"
#include "vector"

class Panel : public Control{
    protected:
        vector <Control*> Controlers;

    public:
        Panel();
        Panel(short left, short top, short width, short height, Border* border, Color textColor, Color backgroundColor);
        ~Panel();
        void addToPanel(Control* controler);
        void draw(Graphics& g, int x, int y, size_t z);
};
