#pragma once
#include <iostream>
#include "string"
#include "Listener.h"
#include "Panel.h"
#include "vector"
#include "Label.h"
#include "Button.h"

class CheckList : public Panel {
    private:
        //string value;
        //vector <Listener*> Listeners;
        int num_of_items;
        int left, top;
        Button option_btn1,option_btn2,option_btn3,option_btn4;
        Label option_lbl1;
        Label option_lbl2;
        Label option_lbl3;
        Label option_lbl4;
        vector<Label> lbl_arr;
        vector<Button> btn_arr;
        vector<string> options;

    public:
        CheckList(int left, int top, vector<string> options);
        void draw(Graphics& g, int x, int y, size_t z);
        bool AddSelectedItem(string item);
        bool RemoveSelectedItem(string item);
};