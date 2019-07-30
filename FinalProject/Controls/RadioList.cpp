#include "RadioList.h"
#include <fstream>

RadioList::RadioList(int left, int top, vector<string> options_lbl) : Panel(left, top, 20, 12, new Single, Color::White, Color::Black),
left(left),top(top),options_lbl(options_lbl)
{
    position_t pos = {0,0};
    for (std::vector<string>::iterator lbl = options_lbl.begin() ; lbl != options_lbl.end(); ++lbl)
    {
        options.push_back(Button(*lbl));
    }
    for(int i=0; i < options.size(); i++ )
    {
        options[i].setTop(i);
        options[i].addListener(this);
        this->addToPanel(&options[i]);
        pos.x = getLeft();
        pos.y = getTop()+i+1;
        options_pos.push_back(pos);
    }
    SelectedItem(0);
}

void RadioList::draw(Graphics& g, int x, int y, size_t z) {
    int controlerX, controlerY;
    if (!z)
        Panel::draw(g, x-1, y-1, z);
}

void RadioList::mousePressed(int x, int y, bool isLeft)
{
    ofstream myfile;
    myfile.open ("mousePressed.txt", std::ios_base::app);
    myfile << options_pos.size() << endl;
    myfile << "Mouse pos - x " << x << " y " << y << endl;
    for(int i=0; i < options_pos.size(); i++){
        myfile << "options pos - x " << std::to_string(options_pos[i].x) << " y " << std::to_string(options_pos[i].y) << endl;
        if(x >= options_pos[i].x && x <= options_pos[i].x + 10 && y >= options_pos[i].y && isLeft == true)
        {
            ClearSelection();
            SelectedItem(i);
        }
    }
    myfile.close();
}

void RadioList::activateListener(int x, int y)
{
    ofstream myfile;
    myfile.open ("activateListener.txt", std::ios_base::app);
    for(int i=0; i < options_pos.size(); i++){
        if(x >= options_pos[i].x && x <= options_pos[i].x + 10 && y >= options_pos[i].y)
        {
            ClearSelection();
            SelectedItem(i);
        }
    }
    myfile.close();
}

bool RadioList::SelectedItem(int index) {
    Color tempColor = options[index].getBackgroundColor();
    options[index].SetBackgroundColor(options[index].getTextColor());
    options[index].SetTextColor(tempColor);
    this->updateFocusedControler(this);
    selectedItem=index;
    return true;
}

bool RadioList::ClearSelection() {
    Color tempColor = options[selectedItem].getBackgroundColor();
    options[selectedItem].SetBackgroundColor(options[selectedItem].getTextColor());
    options[selectedItem].SetTextColor(tempColor);
    this->updateFocusedControler(this);
    return true;
}