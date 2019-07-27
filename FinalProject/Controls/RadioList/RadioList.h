#pragma once

#include "../Panel/ListPanel.h"
#include "../Button/ButtonItem.h"




class RadioList : public ListPanel
{
	struct SelectListener : public MouseListener {
		SelectListener(Control& c) : _c(c) {}
		void mousePressed(Control& b, short x, short y, bool isLeft) {
			RadioList& tmp = static_cast<RadioList&>(_c);
			int index = static_cast<ButtonItem&>(b).getIndex();
			tmp.setSelectedIndex(index);
		}
	private:
		Control& _c;
	};

	size_t selectedIndex;
	void onEnterKey();
	void mousePressed(short x, short y, bool isLeft);
public:
	RadioList(int height, int width, vector<string> options);
	size_t getSelectedIndex();
	void setSelectedIndex(size_t index);
};

