#include "TextBox.h"

const int CONSTANT = CONSTANT;

TextBox::TextBox(int width) : Control(width) , curserPosition(){}

void TextBox::setValue(string _value) {
	value = _value.substr(0, getWidth() - CONSTANT);
	curserPosition = value.substr(0, getWidth() - CONSTANT).length() + 1;
}

string TextBox::getValue() {
	return value;
}

void TextBox::draw(Graphics& g, int x, int y, size_t layer) {
	if (getLayer() != layer) 
		return;

	Control::draw(g, x, y, layer);

	g.setBackground(g.convertToColor(getBackGround()));
	g.setForeground(g.convertToColor(getForeground()));

	string toPrint = value.substr(0, getWidth() - CONSTANT);

	if (toPrint.length() < getWidth() - CONSTANT) {
		toPrint = toPrint + string(getWidth() - CONSTANT - toPrint.length(), ' ');
	}

	g.write(getBodyLeft(), getBodyTop(), toPrint);

	if (isFocus()) {
		if(Control::getFocus() == this) g.setCursorVisibility(true);
	} 

	g.resetColors();
}

int TextBox::getCurserPosition() {
	return curserPosition;
}

void TextBox::keyDown(WORD w, CHAR c) {

	switch (w)
	{
		case VK_DOWN:
		case VK_UP:
		case VK_RETURN:
			break;
		case VK_SHIFT:
			break;
		
		case VK_RIGHT:	
			moveRight();	
			break;
		case VK_LEFT:	
			moveLeft();		
			break;
		case VK_RWIN:	
			moveRight();	
			break;
		case VK_LWIN:	
			moveLeft();		
			break;
		case VK_BACK:	
			deleteLeft();	
			break;
		case VK_DELETE:	
			deleteRight();	
			break;
		default:		
			addCharecter(c);
			break;
	}
}

void TextBox::mousePressed(short x, short y, bool b){
	Control::mousePressed(x, y, b);
}


void TextBox::moveRight(){
	int x = getBodyLeft() + getWidth();
	if (getBodyLeft() + curserPosition > getBodyLeft() +  getWidth() - 3) return;
	curserPosition++;
}

void TextBox::moveCurser(Graphics g) {
	if (getCurserPosition() > getWidth() - CONSTANT) {
		g.moveTo(getBodyLeft() + getCurserPosition() - CONSTANT, getBodyTop());
	}
	else if (curserPosition == 1) {
		g.moveTo(getBodyLeft(), getBodyTop());
	}
	else {
		g.moveTo(getBodyLeft() + getCurserPosition() - 1, getBodyTop());
	}
}

void TextBox::moveLeft(){
	if (!(curserPosition -  1)) 
		return;

	curserPosition--;
}

void TextBox::deleteLeft(){
	if (!(curserPosition - 1) || !value.length()) {
		moveLeft();
		return;
	}

	value.erase(curserPosition - 2, 1);
	moveLeft();
}

void TextBox::deleteLast(){
	value.erase(getWidth() - CONSTANT, 1);
}

void TextBox::deleteRight(){
	if (curserPosition > value.length()) return;
	value.erase(curserPosition - 1, 1);
}

void TextBox::addCharecter(CHAR c){
	if (value.length() == getWidth() - CONSTANT) {
		return;
	}
	else if (!value.length()) {
		value = string("");
		value.insert(0, 1, c);
	}
	else value.insert(curserPosition - 1, 1, c);
	moveRight();
}


TextBox::~TextBox() {}
