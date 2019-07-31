#pragma once
#include <string>
#include "Button.h"
#include "../Common/Border/Border.h"
#include "Panel.h"

using namespace std;

class NumericBox : public Panel, public Listener {
    private: 
        Button inc;
        Button dec;
        Label value;
        int minVal, val, maxVal;

    public:
        NumericBox(int minVal, int maxVal, short left, short top, short width = 5, short height = 3, Border* border = new Single, Color textColor = Color::White, Color backgroundColor = Color::Black);

        void setMinVal(int value) { this->minVal = value; }
        int getMinVal() { return this->minVal; }

        void setMaxVal(int value) { this->maxVal = value; }
        int getMaxVal() { return this->maxVal; }

        void setVal(int value) { this->val = value; }
        int getVal() { return this->val; }

        void draw(Graphics& g, int x, int y, size_t z);

        void mousePressed(int x, int y, bool isLeft);
        void activateListener(int x, int y);
};