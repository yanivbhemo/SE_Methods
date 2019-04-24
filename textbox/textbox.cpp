#include "textbox.h"
#include <iostream>
#include <algorithm>

TextBox::TextBox(short width, short top, short left, std::string value) : 
    width(width), top(top), left(left), value(value), curserPosition(value.length()), hasBorder(true),
    color(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY),
    background(0)  { }

void TextBox::handleKeyboardEvent(KEY_EVENT_RECORD& event)
{
    if (!event.bKeyDown) return;

    if (event.wVirtualKeyCode >= 0x30 && event.wVirtualKeyCode <= 0x5a)
    {
        if (value.length() < width){
            value.insert(curserPosition, 1, event.uChar.AsciiChar);
            curserPosition++;
            draw();
        }
       
    }

    int textWidth = value.length();
    CONSOLE_SCREEN_BUFFER_INFO info;
    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(handle, &info);
    auto offset = info.dwCursorPosition.X - this->left - 1;

    if (event.wVirtualKeyCode == VK_LEFT || event.wVirtualKeyCode == VK_RIGHT){
        if (offset > 0 && event.wVirtualKeyCode == VK_LEFT){
            SetConsoleCursorPosition(handle,{ info.dwCursorPosition.X - 1, info.dwCursorPosition.Y });
            curserPosition--;
        }
        if (offset < textWidth && event.wVirtualKeyCode == VK_RIGHT){
            SetConsoleCursorPosition(handle,{ info.dwCursorPosition.X + 1, info.dwCursorPosition.Y });
            curserPosition++;
        }
    }

    if (event.wVirtualKeyCode == VK_BACK)
    {
        if (value.length() > 0){
            value.erase(curserPosition - 1, 1);
            SetConsoleCursorPosition(handle,{ info.dwCursorPosition.X - curserPosition, info.dwCursorPosition.Y });
            curserPosition--;
            draw();
        }
    }
}

void TextBox::draw()
{
    COORD coord = { left, top };
    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle, coord);
    SetConsoleTextAttribute(handle, color | (background << 4));
    
    std::cout << (char) 0xda;
    for (int i=0; i<width; i++)
        std::cout << (char) 0xc4;
    std::cout << (char) 0xbf;

    SetConsoleCursorPosition(handle, {coord.X, coord.Y+1});
    std::cout << (char) 0xb3;
    
    for (int i =0; i < width; i++)
        std::cout << (i >= value.length() ? ' ' : value[i]);
    
    SetConsoleCursorPosition(handle, { left + width + 1, top + 1 });
    std::cout << (char) 0xb3;

    SetConsoleCursorPosition(handle, { left, top + 2 });
    std::cout << (char) 0xc0;
    for (int i = 0; i < width; i++)
        std::cout << (char) 0xc4;
    std::cout << (char) 0xd9;

    SetConsoleCursorPosition(handle, { left + 1 + value.length(), top+1 });

}

