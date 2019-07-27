#include "RadioList.h"


RadioList::RadioList(int height, int width, vector<string> options) : ListPanel(height, width, options){
	int length = options.size(), i = 0;

	while (i < length) {
		ButtonItem *buttonItem = new ButtonItem(options[i], getWidth() - 4, i);
		buttonItem->setBorder(BorderType::Single);

		SelectListener* selectListener = new SelectListener(*this);
		buttonItem->addListener(*selectListener);

		addControl(buttonItem, getBodyLeft(), getBodyTop() + (i * 3));

		i++;
	}
}

void RadioList::setSelectedIndex(size_t index) {
	clearAllFocus();
	static_cast<ButtonItem*>(controls[index])->toggle();
	switchFocus(index);
}
void RadioList::onEnterKey() {
	if (!(itemInFocus() + 1))
		return;
	setSelectedIndex(itemInFocus());
}

size_t RadioList::getSelectedIndex() {

	getAllControls(controls);
	int size = controls.size();
	for (int i = 0; i < size; i++) {
		if (static_cast<ButtonItem*>(controls[i])->txtMarkedChecker())
			return static_cast<ButtonItem*>(controls[i])->getIndex();
	}
	return -1;
}

void RadioList::mousePressed(short x, short y, bool isLeft) {
	Control::mousePressed(x, y, isLeft);

	int cSize = controls.size();
	for (int i = 0; i < cSize; i++) {
		controls[i]->mousePressed(x, y, isLeft);
	}
}

