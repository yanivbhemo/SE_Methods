#include <iostream>
#include "string"
#include "Panel.h"
#include "vector"
#include "Label.h"
#include "Button.h"

struct position_t {short x; short y; };

class RadioList : public Panel, public Listener {
    private:
        int left, top;
        vector<Button> options;
        vector<string> options_lbl;
        vector<position_t> options_pos;
        int selectedItem = 0;

    public:
        RadioList(int left, int top, vector<string> options_lbl);
        void draw(Graphics& g, int x, int y, size_t z);
        void keyDown(int keyCode, char character);
        void mousePressed(int x, int y, bool isLeft);
        void activateListener(int x, int y);
        bool SelectedItem(int index);
        bool ClearSelection();
};