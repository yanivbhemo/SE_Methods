#include "TextBox.h"

TextBox::TextBox(int left, int top, int width) : Panel(left, top, width, 2, new Single, Color::Cyan, Color::Green)
{
    return;
}