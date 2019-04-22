#include <string>

class Checkbox
{
    private:
        std::string text;
        int left;
        int top;
    
    public:
        Checkbox();
        void setText(std::string);
        void setPosition(int, int);
        std::string getText();
        int getTop();
        int getLeft();
        void draw();
        void HandleClick();
};