#pragma once
#include <string>
#include "Button.h"
#include "../Common/Border/Border.h"
#include "Panel.h"


class messageBox : public Panel, public Listener{

    public:

        messageBox(string message);
        messageBox(string message, short left, short top, short width, short height, Border* border, Color textColor, Color backgroundColor);
        ~messageBox() {}

        void setMessageValue(string messageValue){ this->messageValue.setValue(messageValue); }
        string getMessageValue(){ return messageValue.getValue(); }
            
        void setOKText(string ok) { this->ok = ok; }
        void setCancelText(string cancel){ this->cancel = cancel; }
            
        void setValue(string message) { this->buttonMsgValue = message ;}
        string getValue(){ return this->buttonMsgValue; }

        void draw(Graphics& g, int x, int y, size_t z);

        void mousePressed(int x, int y, bool isLeft);
        void activateListener(int x, int y);
        virtual void okPressed();
        virtual void cancelPressed();


    private:
        Button ok;
        Button cancel;
        Label messageValue;
        string buttonMsgValue;
};