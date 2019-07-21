#include "Border.h"

Border::Border(char topLeft, char topRight, char botLeft, char botRight, char hori, char verti) {
    this->topLeft = topLeft;
    this->topRight = topRight;
    this->botLeft = botLeft;
    this->botRight = botRight;
    this->hori = hori;
    this->verti = verti;
}

void Border::drawBorder(Graphics& g, short left, short top, short width, short height) {
  
}