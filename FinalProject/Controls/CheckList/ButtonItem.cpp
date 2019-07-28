#include "ButtonItem.h"


ButtonItem::ButtonItem(string text, int width, size_t index)
	: Button(width, "[ ] " + text), markAsChecked("[V] " + text), index(index), isCheck(false){}

bool ButtonItem::txtMarkedChecker(){
	return isCheck;
}

void ButtonItem::draw(Graphics &graphics, int x, int y, size_t layer){
	if (getLayer() != layer) return;
	Control::draw(graphics, getLeft(), getTop(), layer);
	if (isFocus()){
		graphics.setBackground(graphics.convertToColor(getForeground()));
		graphics.setForeground(graphics.convertToColor(getBackGround()));
	} else if (txtMarkedChecker()){
		graphics.setBackground(graphics.convertToColor(BackgroundColor::Blue));
		graphics.setForeground(graphics.convertToColor(ForegroundColor::White));
	} else {
		graphics.setBackground(graphics.convertToColor(getBackGround()));
		graphics.setForeground(graphics.convertToColor(getForeground()));
	}
	graphics.write(getBodyLeft(), getBodyTop(), getValue());
	graphics.resetColors();
}
void ButtonItem::toggle(){
	isCheck = !isCheck;
	string tmp = text;
	text = markAsChecked;
	markAsChecked = tmp;
}


size_t ButtonItem::getIndex(){
	return index;
}

ButtonItem::~ButtonItem(){}
