#include "CheckList.h"


CheckList::CheckList(int height, int width, vector<string> options) : ListPanel(height, width, options){
	int length = options.size();
	int i = 0;
	while (i < length) {
		ButtonItem *btn = new ButtonItem(options[i], getWidth() - 4, i);
		btn->setBorder(BorderType::Single);
		SelectListener* listener = new SelectListener(*this);
		btn->addListener(*listener);
		addControl(btn, getBodyLeft(), getBodyTop() + (i * 3));

		i++;
	}
}

vector<size_t> CheckList::getSelectedIndices(){
	vector<size_t> selected;
	getAllControls(controls);
	int cSize = controls.size();
	for (int i = 0; i < cSize; i++){
		if (static_cast<ButtonItem*>(controls[i])->txtMarkedChecker()) selected.push_back(i);
	}
	return selected;
}

void CheckList::selectIndex(size_t index){
	static_cast<ButtonItem*>(controls[index])->toggle();
}

void CheckList::deselectIndex(size_t index){
	static_cast<ButtonItem*>(controls[index])->toggle();
}

void CheckList::onEnterKey(){
	selectIndex(itemInFocus());
}

void CheckList::mousePressed(short x, short y, bool isLeft){
	Control::mousePressed(x, y, isLeft);

	int cSize = controls.size();
	for (int i = 0; i < cSize; i++) {
		controls[i]->mousePressed(x, y, isLeft);
	}
}
