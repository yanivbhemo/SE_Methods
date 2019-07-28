#include "ListPanel.h"


ListPanel::ListPanel(int height, int width, vector<string> options) : Panel(height, width){
}

int ListPanel::itemInFocus(){
	int cSize = controls.size();
	for (size_t i = 0; i < cSize; i++){
		if (static_cast<ButtonItem*>(controls[i])->isFocus()){
			return i;
		}
	}
	static_cast<ButtonItem*>(controls[0])->focus();
	return 0;
}

void ListPanel::keyDown(WORD click, CHAR chr){
	if (click == VK_RETURN) {
		onEnterKey();
	} else if (click == VK_DOWN || click == VK_NUMPAD2) { 
		onDownKey();
	}
	else if (click == VK_UP || click == VK_NUMPAD8) {
		onUpKey();
	}
}

void ListPanel::onDownKey(){
	int item = itemInFocus();
	if(!(item + 1)) item = 0;
	else {
		controls[item]->unfocus();
		if (item >= controls.size() - 1) item = 0;
		else item += 1;
	}
	 
	controls[item]->focus();
}

void ListPanel::onUpKey(){
	int item = itemInFocus();
	if (!(item+1)) item = 0;
	else {
		controls[item]->unfocus();
		if (item == 0) item = controls.size() - 1;
		else item -= 1;
	}
	
	controls[item]->focus();
}

void ListPanel::onEnterKey(){} 

void ListPanel::setForeground(ForegroundColor color) {
	Control::setForeground(color);
	int cSize = controls.size();
	for (int i = 0; i < cSize; i++) {
		controls[i]->setForeground(color);
	}
}

void ListPanel::setBackGround(BackgroundColor color) {
	Control::setBackGround(color);
	int cSize = controls.size();
	for (int i = 0; i < cSize; i++) {
		controls[i]->setBackGround(color);
	}
}

void ListPanel::switchFocus(int indx){
	int tmp = itemInFocus();
	if (tmp != -1) controls[tmp]->unfocus();
	controls[indx]->focus();
}

void ListPanel::clearAllFocus() {
	int size = controls.size();
	for (int i = 0; i < size; i++) {
		if(static_cast<ButtonItem*>(controls[i])->txtMarkedChecker())
			static_cast<ButtonItem*>(controls[i])->toggle();
	}
}

void ListPanel::unfocus(){
	Panel::unfocus();
	int size = controls.size();
	for (int i = 0; i < size; i++) {
		static_cast<ButtonItem*>(controls[i])->unfocus();
	}
}


