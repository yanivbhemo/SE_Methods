#include <string>

class Checkbox
{
    private:
        std::string text;
        int left;
        int top;
        bool checked;
    
    public:
        Checkbox();
        Checkbox(std::string text, int left, int top);
        void setText(std::string);
        void setPosition(int, int);
        void setChecked(bool check);
        bool getChecked();
        std::string getText();
        int getTop();
        int getLeft();
        void draw();
        void HandleClick();
};