#include "RadioList.h"
#include <fstream>

RadioList::RadioList(int left, int top, vector<string> options_lbl) : Panel(left, top, 20, 12, new Single, Color::Black, Color::White),
left(left),top(top),options_lbl(options_lbl)
{
    ofstream myfile;
    // myfile.open ("example3.txt", std::ios_base::app);
    // myfile << options_lbl[0] << endl;
    // myfile.close();
}

void RadioList::draw(Graphics& g, int x, int y, size_t z) {
    int controlerX, controlerY;
    if (!z)
        Panel::draw(g, x-1, y-1, z);
}

void RadioList::mousePressed(int x, int y, bool isLeft)
{
    ofstream myfile;
    myfile.open ("example3.txt", std::ios_base::app);
    myfile << x << " " << y << endl;
    myfile.close();
}

void RadioList::activateListener(int x, int y)
{
    ofstream myfile;
    myfile.open ("example2.txt", std::ios_base::app);
    myfile << x << " " << y << endl;
    myfile.close();
}