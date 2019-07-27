#pragma once

#include "../Panel/ListPanel.h"
#include "../Button/ButtonItem.h"
#include "../Label/Label.h"



class ComboBox : public ListPanel
{
	struct SelectListener : public MouseListener {
		SelectListener(Control& c) : _c(c) {}
		void mousePressed(Control& b, short x, short y, bool isLeft) {
			ComboBox& tmp = static_cast<ComboBox&>(_c);
			int index = static_cast<ButtonItem&>(b).getIndex();
			tmp.setSelectedIndex(static_cast<ButtonItem&>(b).getIndex());
		}
	private:
		Control& _c;
	};

	struct ToggleListener : public MouseListener {
		ToggleListener(Control& c) : _c(c) {}
		void mousePressed(Control& b, short x, short y, bool isLeft) {
			ComboBox& tmp = static_cast<ComboBox&>(_c);
			tmp.toggle();
		}
	private:
		Control& _c;
	};

	Label *choosenItem;
	Button *toogleBtn;
	int choosenIndex;
	size_t selectedIndex;
	bool isOpen;
	int openHeight, closeHeight;
	void onDownKey();
	void onUpKey();
	void onEnterKey();
public:
	ComboBox(int width, vector<string> options); 
	size_t getSelectedIndex();
	void setSelectedIndex(size_t);
	void draw(Graphics &graphics, int, int, size_t);
	void mousePressed(short, short, bool);
	void toggle();
	void unfocus();
	void openList();
	void closeList();

	~ComboBox();
};

