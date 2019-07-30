#include "RadioList.h"
#include <fstream>

RadioList::RadioList(int left, int top, vector<Button> options) : Panel(left, top, 20, 12, new Single, Color::Black, Color::White),
left(left),
top(top)
{
    options = options;
    // for(int i=0; i<options.size(); i++){
    //     this->options[i].setTop(top+i);
    //     this->options[i].setLeft(left);
    //     this->options[i].addListener(this);
    //     this->addToPanel(&options[i]);
    //     return;
    // }
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