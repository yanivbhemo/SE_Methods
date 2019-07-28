#pragma once

#include "Panel.h"
#include "../Button/ButtonItem.h"

class ListPanel : public Panel
{
protected:
	int itemInFocus();
	void switchFocus(int indx);
	void clearAllFocus();
	virtual void onDownKey();
	virtual void onUpKey();
	virtual void onEnterKey();
	void unfocus();
public:
	ListPanel(int height, int width, vector<string> options);
	void setForeground(ForegroundColor color);
	void setBackGround(BackgroundColor color);
	void keyDown(WORD, CHAR);
};

