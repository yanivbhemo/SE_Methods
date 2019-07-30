#include <iostream>
#include "string"
#include "Panel.h"
#include "vector"
#include "Label.h"
#include "Button.h"

class RadioList : public Panel, public Listener {
    private:
        int left, top;
        vector<Button> options;

    public:
        RadioList(int left, int top, vector<Button> options);
        void draw(Graphics& g, int x, int y, size_t z);
        void mousePressed(int x, int y, bool isLeft);
        void activateListener(int x, int y);
};