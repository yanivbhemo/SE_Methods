#include "MsgBox.h"


MsgBox::MsgBox(int height, int width) : Panel(height, width)
{
	result = NULL;
	setLayer(2);
	isfocusable = false;
	
	Button *accept = new Button(width/4, Label::centerlizeTxt(width/4, "Accept"));
	Button *decline = new Button(width/4, Label::centerlizeTxt(width/4, "Decline"));

	Label *title = new Label(width-2, "Form Confirmation");
	Label *text = new Label(width-2, "Do u accept the terms?");
	
	AcceptListener  *acceptListener = new AcceptListener(*this);	
	DeclineListener *declineListener = new DeclineListener(*this);
	
	title->setLayer(2);	
	title->setBackGround(BackgroundColor::Blue);

	text->setLayer(2);
	text->setBackGround(BackgroundColor::Blue);

	accept->addListener(*acceptListener);
	accept->setLayer(2);
	accept->setBorder(BorderType::Single);
	accept->setBackGround(BackgroundColor::Green);	
	decline->addListener(*declineListener);
	decline->setLayer(2);
	decline->setBorder(BorderType::Single);
	decline->setBackGround(BackgroundColor::Red);

	addControl(title, 1,1);
	addControl(text,1,4);	
	addControl(accept, 3, height-5);
	addControl(decline, width-3-(width/4), height-5);
}

void MsgBox::setResult(bool b) {
	result = b;
}

void MsgBox::mousePressed(short x, short y, bool isLeft) {
	short left = this->getLeft(), top = this->getTop(), width = this->getWidth(), height = this->getHeight();
	if (x < left || (x > left + width) || y < top || (y > top + height)) 
	{
		if (isVisible()) hide();
	}

	for (int i = 2; i < controls.size(); i++) {
		controls[i]->mousePressed(x, y, isLeft);
	}		

	//after pressed one of the buttons: this->result will set to TRUE or FALSE accordingly.
}

void MsgBox::setText(string text) {
	static_cast<Label*>(controls[1])->setValue(text);
}

void MsgBox::setTitle(string text) {
	static_cast<Label*>(controls[0])->setValue(text);
}

void MsgBox::keyDown(WORD click, CHAR chr){
	if (click == VK_RETURN) hide();
}

void MsgBox::show(){
	Control::show();
	openButtonMessage();
}

void MsgBox::hide(){
	Control::hide();
	closeButtonMessage();
}

