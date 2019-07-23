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
    string line(width, hori);
    string cleaner(width, ' ');
    g.moveTo(left, top);
    std::cout << topLeft << line << topRight;
    for(int i = 1; i < height - 1; ++i) {
        g.moveTo(left, top + i);
        std::cout << verti; // print left pipe
        std::cout << cleaner; // clear the inside of the control
        std::cout << verti; // print right pipe
    }
    g.moveTo(left, top + height - 1);
    std::cout << botLeft << line << botRight;
}