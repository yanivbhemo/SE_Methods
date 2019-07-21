#pragma once
#include <iostream>
#include <string>
#include "../Graphics.h"

class Border {

    protected:
        char topLeft;
        char topRight;
        char botLeft;
        char botRight;
        char hori;
        char verti;

    public:
        Border() {};
        Border(char topLeft, char topRight, char botLeft, char botRight, char hori, char verti);
        virtual ~Border() {};
        virtual void drawBorder(Graphics& g, short left, short top, short width, short height);
};
