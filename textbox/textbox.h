#include <string>
#include <windows.h>

class TextBox
{
    public:
        short width;
        short top;
        short left;
        short curserPosition;
        bool hasBorder;
        WORD color;
        WORD background;
        std::string value;
        TextBox(short width, short top, short left, std::string value);
        void draw();
        void handleKeyboardEvent(KEY_EVENT_RECORD&);
};