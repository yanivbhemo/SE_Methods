#pragma once
#include "Graphics.h"
#include "./Border/Border.h"
#include "Border/None.h"
#include "Border/Single.h"
#include "Border/Double.h"
#include <vector>

using namespace std;

class Control
{

protected:
	short left;
	short top;
	short width;
	short height;
	Border* border;
	Color textColor;
	Color backgroundColor;
	bool visible;
	static Control* focused;

	
public:
	Control();
	Control(short left, short top, short width, short height, Border* border, Color textColor, Color backgroundColor);
	static Control* getFocus() { return focused; };
	static void setFocus(Control& control);

	void setBorder(Border* newBorder);

	virtual short getLeft() { return left; }
	virtual void setLeft(short left) { this->left = left; }

	virtual short getTop() { return top; }
	virtual void setTop(short top) { this->top = top; }

	virtual short getWidth() { return width; }
	virtual void setWidth(short width) { this->width = width; }

	virtual short getHeight() { return height; }
	virtual void setHeight(short height) { this->height = height; }

	virtual Color getTextColor() { return textColor; }
	virtual void SetTextColor(Color textColor) { this->textColor = textColor; }

	virtual Color getBackgroundColor() { return backgroundColor; }
	virtual void SetBackgroundColor(Color backgroundColor) { this->backgroundColor = backgroundColor; }
	
	virtual void SetVisability(bool visibility) { this->visible = visibility; }

	virtual void draw(Graphics& g, int x, int y, size_t z);
	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char charecter) {};
	virtual void getAllControls(vector<Control*>* controls) {};
	virtual bool canGetFocus() { return false; };


	~Control();
};

