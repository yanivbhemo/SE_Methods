#include "CheckList.h"
#include <fstream>

CheckList::CheckList(int left, int top, vector<string> options) : Panel(left, top, 20, 10, new Single, Color::Cyan, Color::Green),
option_lbl1(options[0]),option_lbl2(options[1]),option_lbl3(options[2]),option_lbl4(options[3]),
option_btn1("[ ]"),option_btn2("[ ]"),option_btn3("[ ]"),option_btn4("[ ]")
{
    this->num_of_items = options.size();
    this->options = options;
    option_lbl1.setLeft(3);option_lbl2.setLeft(3);option_lbl3.setLeft(3);option_lbl4.setLeft(3);
    option_lbl2.setTop(option_lbl1.getTop()+2);
    option_lbl3.setTop(option_lbl2.getTop()+2);
    option_lbl4.setTop(option_lbl3.getTop()+2);
    option_btn2.setTop(option_btn1.getTop()+2);
    option_btn3.setTop(option_btn2.getTop()+2);
    option_btn4.setTop(option_btn3.getTop()+2);
    option_btn1.addListener(this);
    option_btn2.addListener(this);
    option_btn3.addListener(this);
    option_btn4.addListener(this);
    this->lbl_arr.push_back(option_lbl1);
    this->lbl_arr.push_back(option_lbl2);
    this->lbl_arr.push_back(option_lbl3);
    this->lbl_arr.push_back(option_lbl4);
    this->addToPanel(&option_btn1);
    this->addToPanel(&option_lbl1);
    this->addToPanel(&option_btn2);
    this->addToPanel(&option_lbl2);
    this->addToPanel(&option_btn3);
    this->addToPanel(&option_lbl3);
    this->addToPanel(&option_btn4);
    this->addToPanel(&option_lbl4);
    // option_btn1.mousePressed(this->getLeft()+1,this->getTop(),true);
}

void CheckList::draw(Graphics& g, int x, int y, size_t z) {
    int controlerX, controlerY;
    if (!z)
        Panel::draw(g, x-1, y-1, z);
}

bool CheckList::AddSelectedItem(string item) {
    options.push_back(item);
    num_of_items++;
    Label l1(item);
    l1.setTop((num_of_items-1)*2);
    l1.setLeft(3);
    Button b1("[ ]");
    b1.setTop((num_of_items-1)*2);
    this->lbl_arr.push_back(l1);
    this->btn_arr.push_back(b1);
    this->btn_arr[this->btn_arr.size()-1].addListener(this);
    this->addToPanel(&this->lbl_arr[this->lbl_arr.size()-1]);
    this->addToPanel(&this->btn_arr[this->btn_arr.size()-1]);
    return true;
}

bool CheckList::RemoveSelectedItem(string item){
    for(int i=0;i<num_of_items;i++)
    {
        if(options[i] == item){
            this->lbl_arr[i].setValue("");
            // if(i<num_of_items-1){
            //     for(int j=i+1; j<num_of_items; j++){
                    
            //     }
            // }
            this->addToPanel(&lbl_arr[i]);
        }
    }
    return true;
}

void CheckList::mousePressed(int x, int y, bool isLeft)
{
    ofstream myfile;
    myfile.open ("example1.txt", std::ios_base::app);
    myfile << x << " " << y << endl;
    myfile.close();
}

void CheckList::activateListener(int x, int y)
{
    ofstream myfile;
    myfile.open ("example2.txt", std::ios_base::app);
    myfile << x << " " << y << endl;
    myfile.close();
}