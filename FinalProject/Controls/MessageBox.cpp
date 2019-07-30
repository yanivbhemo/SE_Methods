#include "MessageBox.h"
#include <iostream>
#include <fstream>


messageBox::messageBox(string message) : 
    Panel(0, 0, 1, 1, new Single, Color::White, Color::Black),
    ok(Button("OK")),
    cancel(Button("Cancel")),
    messageValue(Label(message))
    /* textMsgValue(message) */ {
        this->SetVisability(false);
        this->setWidth(ok.getWidth() + cancel.getWidth() + messageValue.getValue().length() + 4);
        this->setHeight(6);
        this->setLeft(2);
        this->setTop(2);
        messageValue.setTop(0);
        messageValue.setLeft(3);
        ok.setLeft(getLeft());
        ok.setTop(getHeight() - 3);
        cancel.setLeft(getWidth() - 7);
        cancel.setTop(getHeight() - 3);
        ok.addListener(this);
        cancel.addListener(this);
        this->addToPanel(&messageValue);
        this->addToPanel(&ok);
        this->addToPanel(&cancel);
    }

// messageBox::messageBox(string message, short left, short top, short width, short height, Border* border, Color textColor, Color backgroundColor) :
//     Panel(0, 0, 1, 1, new Single, Color::White, Color::Black),
//     ok(Button("OK")),
//     cancel(Button("CANCEL")),
//     textMsgValue(message),
//     messageValue(Label(message)) {
//         this->SetVisability(false);

//         ok.SetBackgroundColor(Color::Purple);
//         cancel.SetBackgroundColor(Color::Orange);

//         this->setWidth(ok.getWidth() + cancel.getWidth() + messageValue.getValue().length() + 4);
//         this->setHeight(6);
//         this->setLeft(2);
//         this->setTop(2);

//         ok.addListener(this);
//         cancel.addListener(this);
//         this->addToPanel(&messageValue);
//         this->addToPanel(&ok);
//         this->addToPanel(&cancel);
//     } 


void messageBox:: draw(Graphics& g, int x, int y, size_t z){
    ofstream myfile;
    myfile.open ("example.txt");
    myfile << "message" << endl;
    
    if (visible && !z){
        int controlerX, controlerY;
        // x = 2;
        // y = 2;
        // width = ok.getWidth() + cancel.getWidth() + messageHeader.getValue().length() + 1;
        // height = messageHeader.getHeight() + 4;
        Panel::draw(g, x-1, y-1, z);
        // for (int index = 0; Controlers.size() > index; index++){
        //     myfile << "in for" << endl;
        //     controlerX = Controlers[index]->getLeft();
        //     // if (Controlers[index]->getTop() == 0)
        //     //     controlerY = Controlers[index]->getTop() + index - 1;
        //     // else
        //     controlerY = Controlers[index]->getTop();
        //     g.setBackground(Controlers[index]->getBackgroundColor());
        //     g.setForeground(Controlers[index]->getTextColor());
        //     Controlers[index]->draw(g, controlerX + x + 1, controlerY + y + 1, z);
        // }

        // message_.draw(g, center, y, 0);
        // ok.draw(g, center + 1, y+3, 0);
        // cancel.draw(g, center + 7, y+3, 0);


        
    }
    myfile.close();

}

void messageBox::mousePressed(int x, int y,bool isLeft){
      if (isInside(x,y, getLeft() + ok.getLeft() + 1, getTop() + ok.getTop() + 1, getWidth() + ok.getWidth(), getHeight() + ok.getHeight())){
        ok.mousePressed(x, y, isLeft);
    }
    else if (isInside(x,y, getLeft() + cancel.getLeft() + 1, getTop() + cancel.getTop() + 1, getWidth() + cancel.getWidth(), getHeight() + cancel.getHeight())){
        cancel.mousePressed(x, y, isLeft);
    }
}

void messageBox::activateListener(int x, int y){
    if (isInside(x,y, getLeft() + ok.getLeft() - 1, getTop() + ok.getTop(), /* getWidth() + */ ok.getWidth() + 1, /* getHeight() + */ ok.getHeight() + 1)) {
        okPressed();
    }
    if (isInside(x,y, getLeft() + cancel.getLeft() + 1, getTop() + cancel.getTop(), /* getWidth() + */ cancel.getWidth() -1, /* getHeight() + */ cancel.getHeight() + 1)) {
        cancelPressed();
    }
    ofstream myfile;
	myfile.open("example2.txt");
	myfile << this->getValue() << endl;
	myfile.close();
}

void messageBox::okPressed(){
    this->SetVisability(false);
    buttonMsgValue = "OK";
    // return textMsgValue;
}

void messageBox::cancelPressed(){
    this->SetVisability(false);
    buttonMsgValue = "CANCEL";
    // return textMsgValue;

}