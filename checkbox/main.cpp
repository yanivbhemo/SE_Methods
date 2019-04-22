#include "label.h"
#include "checkbox.h"

int main(int argc, char** argv){
    Label l;
    int label1_left = 0, label1_top = 0;
    Checkbox c1;
    int c1_left = label1_left, c1_top = label1_top+1;

    l.setText("Hello Checkbox");
    l.setPosition(label1_left, label1_top);
    l.draw();
    // c1.setText("test");
    // c1.setPosition(c1_left, c1_top);
    // c1.draw();
    while(true);
}