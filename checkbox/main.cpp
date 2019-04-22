#include "label.h"

int main(int argc, char** argv){
    Label l;
    l.setText("Hello Yaniv");
    l.setPosition(0,0);
    l.draw();
    while(true);
}