#include <string>

class Label
{
    private:
        std::string text;
        int left;
        int top;

    public:
        Label();
        void setText(std::string);
        void setPosition(int, int);
        std::string getText();
        int getTop();
        int getLeft();

        void draw();
};