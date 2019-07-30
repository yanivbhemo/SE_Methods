#include "../Common/Control.h"
#include <iostream>

class TextBox : public Control
{
	string value;

	int curserPosition;
	void moveRight();
	void moveLeft();
	void deleteRight();
	void deleteLeft();
	void deleteLast();
	void addCharecter(CHAR c);

public:
	TextBox(short left, short top, short width, short height, Border* border, Color textColor, Color backgroundColor);
	void setValue(string value);
	string getValue();
	void draw(Graphics &graphics, int, int, size_t);
	void keyDown(WORD, CHAR);
	void mousePressed(short, short, bool);
	int getCurserPosition();
	void moveCurser(Graphics);
};

