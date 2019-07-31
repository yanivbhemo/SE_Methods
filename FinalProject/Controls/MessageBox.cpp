#include "MessageBox.h"
#include <iostream>
#include <fstream>

messageBox::messageBox(string message) : 
    Panel(0, 0, 1, 1, new Single, Color::White, Color::Black),
    ok(Button("<OK>")),
    cancel(Button("<Cancel>")),
    messageValue(Label(message)) {
        this->SetVisability(false);
        this->setWidth(ok.getWidth() + cancel.getWidth() + messageValue.getValue().length() + 4);
        this->setHeight(6);
        this->setLeft(2);
        this->setTop(2);
        messageValue.setTop(0);
        messageValue.setLeft(3);
        ok.setLeft(getLeft());
        ok.setTop(getHeight() - 3);
        cancel.setLeft(getWidth() - 10);
        cancel.setTop(getHeight() - 3);
        ok.addListener(this);
        cancel.addListener(this);
        this->addToPanel(&messageValue);
        this->addToPanel(&ok);
        this->addToPanel(&cancel);
}

void messageBox:: draw(Graphics& g, int x, int y, size_t z){
    if (visible && !z){
        Control::lock_events();
        Panel::draw(g, x-1, y-1, z);
    }
    else if (!visible)
        Control::enable_events();
}

void messageBox::mousePressed(int x, int y,bool isLeft){
    // ofstream myfile;
	// myfile.open("if test mousepressed message.txt");

	// myfile << "X: " << x << " Y: " << y << endl;
    // myfile << "ok left: " << getLeft() + ok.getLeft() + 1 << " ok top: " << getTop() + ok.getTop() + 1 << endl;
    // myfile << "ok width: " << ok.getWidth() << " ok height: " << ok.getHeight() << endl;
    // myfile << "cancel left: " << getLeft() + cancel.getLeft() + 1 << " cancel top: " << getTop() + cancel.getTop() + 1 << endl;
    // myfile << "cancel width: " << cancel.getWidth() << " cancel height: " << cancel.getHeight() << endl;
    if (isInside(x,y, getLeft() + ok.getLeft() + 1, getTop() + ok.getTop() + 1, ok.getWidth(), ok.getHeight())){
        ok.mousePressed(x, y, isLeft);
    }
    else if (isInside(x,y, getLeft() + cancel.getLeft() + 1, getTop() + cancel.getTop() + 1, cancel.getWidth(), cancel.getHeight())){
        cancel.mousePressed(x, y, isLeft);
    }
    // myfile.close();
}

void messageBox::activateListener(int x, int y){
    // ofstream myfile;
	// myfile.open("if test activate message.txt");
    // myfile << "X: " << x << " Y: " << y << endl;
    // myfile << "ok left: " << getLeft() + ok.getLeft() + 1 << " ok top: " << getTop() + ok.getTop() + 1 << endl;
    // myfile << "ok width: " << ok.getWidth() << " ok height: " << ok.getHeight() << endl;
    // myfile << "cancel left: " << getLeft() + cancel.getLeft() + 1 << " cancel top: " << getTop() + cancel.getTop() + 1 << endl;
    // myfile << "cancel width: " << cancel.getWidth() << " cancel height: " << cancel.getHeight() << endl;
    if (visible) {
        if (isInside(x,y, getLeft() + ok.getLeft() + 1, getTop() + ok.getTop() + 1, ok.getWidth(), ok.getHeight())) {
            okPressed();
        }
        if (isInside(x,y, getLeft() + cancel.getLeft() + 1, getTop() + cancel.getTop() + 1, cancel.getWidth(), cancel.getHeight())) {
            cancelPressed();
        }
    }
    else {
        Control::lock_events();
    }
}

void messageBox::okPressed(){
    this->SetVisability(false);
    buttonMsgValue = "OK";
    Control::enable_events();
}

void messageBox::cancelPressed(){
    this->SetVisability(false);
    buttonMsgValue = "CANCEL";
    Control::enable_events();
}