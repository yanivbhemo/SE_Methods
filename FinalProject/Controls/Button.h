#pragma once
#include "Label.h"
#include <iostream>
#include "string"
#include "Listener.h"

class Button : public Label {
    private:
        string value;
        vector <Listener*> Listeners;

    public:
        Button(string value);
        ~Button() {};

        void addListener(Listener* listner);
        virtual void mousePressed(int x, int y, bool isLeft);

        void setValue(string);
        string getValue();
        void draw(Graphics& g, int x, int y, size_t z);
        
};