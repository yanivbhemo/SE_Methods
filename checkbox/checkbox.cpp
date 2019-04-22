#include "console.h"
#include "checkbox.h"
#include <iostream>
#include <stdio.h>

VOID ErrorExit(LPSTR);
COORD MouseEventProc(MOUSE_EVENT_RECORD mer);

Checkbox::Checkbox() { }

void Checkbox::setPosition(int left, int top) {
    this->left = left;
    this->top = top;
}

void Checkbox::setText(std::string text)
{
    this->text = "[ ] " + text;
}

int Checkbox::getLeft() { return this->left; }

int Checkbox::getTop() { return this->top; }

std::string Checkbox::getText() { return this->text; }

void Checkbox::draw()
{
    //windows console uses COORD structure to identify position inside the console
    COORD position = { left, top };
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(out,position);
    std::cout << this->text;
    //SetConsoleTextAttribute(out, info.wAttributes);
	//SetConsoleCursorPosition(out, info.dwCursorPosition);

}