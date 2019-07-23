#pragma once
#include "../Common/Control.h"
#include <string>


using namespace std;

class Label: public Control
{   
    private:
        string value;
    public:
        Label(short left, short top, short width, short height, Border* border, Color textColor, Color backgroundColor, string value);
        string getValue();
        void setValue(string);
        void draw(Graphics& g, int x, int y, size_t z);
};