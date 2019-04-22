#include "console.h"
#include "checkbox.h"
#include <iostream>

Checkbox::Checkbox() { }
    //this->text = "[ ]"; 


// void Checkbox::setPosition(int left, int top) {
//     this->left = left;
//     this->top = top;
// }

// void Checkbox::setText(std::string text)
// {
//     //this->text += " " + text;
//     this->text = text;
// }

// int Checkbox::getLeft() { return this->left; }

// int Checkbox::getTop() { return this->top; }

// std::string Checkbox::getText() { return this->text; }

// void Checkbox::draw()
// {
//     //windows console uses COORD structure to identify position inside the console
//     COORD position = { left, top };
//     COORD cursor_position = { left+8, top };
    
//     HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
// 	CONSOLE_SCREEN_BUFFER_INFO info;
    
// 	GetConsoleScreenBufferInfo(out, &info);
// 	SetConsoleCursorPosition(out,position);
//     std::cout << this->text;
//     SetConsoleTextAttribute(out, info.wAttributes);
// 	SetConsoleCursorPosition(out, info.dwCursorPosition);
// }