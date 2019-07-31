#include "CheckList.h"
#include <fstream>

CheckList::CheckList(int left, int top, vector<string> options_lbl) : Panel(left, top, 20, 12, new Single, Color::Green, Color::Purple),
left(left),top(top),options_lbl(options_lbl)
{
    position_s pos = {0,0};
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
}

void CheckList::draw(Graphics& g, int x, int y, size_t z) {
    int controlerX, controlerY;
    if (!z)
        Panel::draw(g, x-1, y-1, z);
}

void CheckList::keyDown(int keyCode, char character)
{
    ofstream myfile;
    myfile.open ("keyDown.txt", std::ios_base::app);
    myfile << "test" << endl;
    myfile.close();
}

void CheckList::mousePressed(int x, int y, bool isLeft)
{
    if (!Control::lockEvent){
        for(int i=0; i < options_pos.size(); i++){
            if(x >= options_pos[i].x && x <= options_pos[i].x + 10 && y >= options_pos[i].y && isLeft == true)
            {
                //ClearSelection();
                AddSelectedItem(i);
            }
        }
    }
}

void CheckList::activateListener(int x, int y)
{
    ofstream myfile;
    myfile.open ("activateListener.txt", std::ios_base::app);
    for(int i=0; i < options_pos.size(); i++){
        if(x >= options_pos[i].x && x <= options_pos[i].x + 10 && y >= options_pos[i].y)
        {
            //ClearSelection();
            AddSelectedItem(i);
        }
    }
    myfile.close();
}

bool CheckList::AddSelectedItem(int index) {
    Color tempColor = options[index].getBackgroundColor();
    options[index].SetBackgroundColor(options[index].getTextColor());
    options[index].SetTextColor(tempColor);
    this->updateFocusedControler(this);
    return true;
}

bool CheckList::ClearSelection() {
    Color tempColor = options[selectedItem].getBackgroundColor();
    options[selectedItem].SetBackgroundColor(options[selectedItem].getTextColor());
    options[selectedItem].SetTextColor(tempColor);
    this->updateFocusedControler(this);
    return true;
}