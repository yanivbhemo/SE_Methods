#include <iostream>
#include "string"
#include "Panel.h"
#include "vector"
#include "Label.h"
#include "Button.h"

class RadioList : public Panel, public Listener {
    private:
        int left, top;
        //vector<Button> options;
        vector<string> options_lbl;
    public:
        RadioList(int left, int top, vector<string> options_lbl);
        void draw(Graphics& g, int x, int y, size_t z);
        void mousePressed(int x, int y, bool isLeft);
        void activateListener(int x, int y);
};