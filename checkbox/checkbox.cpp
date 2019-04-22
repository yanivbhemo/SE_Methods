#include "console.h"
#include "checkbox.h"
#include <iostream>
#include <stdio.h>

VOID ErrorExit(LPSTR);
COORD MouseEventProc(MOUSE_EVENT_RECORD mer);

Checkbox::Checkbox() { }

Checkbox::Checkbox(std::string text, int left, int top) {
    this->text = "[ ] " + text;
    this->left = left;
    this->top = top;
    this->checked = false;
}

void Checkbox::setPosition(int left, int top) {
    this->left = left;
    this->top = top;
}

void Checkbox::setText(std::string text)
{
    this->text = "[ ] " + text;
}

void Checkbox::setChecked(bool check)
{
    this->checked = check;
}

bool Checkbox::getChecked() { return this->checked; }

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