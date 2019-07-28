#pragma once

#include "Button.h"
#include <string>

using namespace std;

class ButtonItem : public Button
{
	string markAsChecked;
	bool isCheck;
	size_t index;
public:
	ButtonItem(string text, int width, size_t index);
	bool txtMarkedChecker();
	void toggle();
	void draw(Graphics &graphics, int x, int y, size_t w);
	size_t getIndex();
	~ButtonItem();
};

