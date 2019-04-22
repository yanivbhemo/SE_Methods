#include "console.h"
#include "label.h"
#include <iostream>

Label::Label() {}

void Label::setPosition(int left, int top) {
    this->left = left;
    this->top = top;
}

void Label::setText(std::string text)
{
    this->text = text;
}

int Label::getLeft() { return this->left; }
int Label::getTop() { return this->top; }
std::string Label::getText() { return this->text; }

void Label::draw()
{
    //windows console uses COORD structure to identify position inside the console
    COORD position = { left, top };
    
    
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);\
	CONSOLE_SCREEN_BUFFER_INFO info;
    
	GetConsoleScreenBufferInfo(out, &info);
	SetConsoleCursorPosition(out,position);
    std::cout << this->text;
    SetConsoleTextAttribute(out, info.wAttributes);
	SetConsoleCursorPosition(out, info.dwCursorPosition);
}
