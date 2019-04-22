#include <windows.h>
#include "label.h"
#include "checkbox.h"

#define AMOUNT_OF_ITEMS 5

void HandleClick(Checkbox item_list[]);
void MouseEventProc(MOUSE_EVENT_RECORD mer, Checkbox item_list[]);

int main(int argc, char** argv){
    Label l;
    int label1_left = 0, label1_top = 0;
    Checkbox c1("Option 1",label1_left,label1_top+1);
    Checkbox c2("Option 2",label1_left,c1.getTop()+1);
    Checkbox item_list [AMOUNT_OF_ITEMS];

    l.setText("Hello Checkbox");
    l.setPosition(label1_left, label1_top);
    l.draw();
    c1.draw();
    item_list[0] = c1;
    c2.draw();
    item_list[1] = c2;
    while(true){
        HandleClick(item_list);
    }
    return 0;
}

void HandleClick(Checkbox item_list[])
{
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD cNumRead, i, fdwMode, fdwSaveOldMode;
    INPUT_RECORD irInBuf[128]; 

    GetConsoleMode(hStdin, &fdwSaveOldMode);
    
    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT; 
    SetConsoleMode(hStdin, fdwMode);
    //while(true){
        ReadConsoleInput( 
                    hStdin,      // input buffer handle 
                    irInBuf,     // buffer to read into 
                    128,         // size of read buffer 
                    &cNumRead); // number of records read 
        if(irInBuf[0].EventType == MOUSE_EVENT) 
        { 
            MouseEventProc(irInBuf[0].Event.MouseEvent, item_list); 
        }
    //}
}

void MouseEventProc(MOUSE_EVENT_RECORD mer, Checkbox item_list[])
{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
    COORD mousePos = mer.dwMousePosition;
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    LPVOID irInBuf[128]; 
    DWORD len;
	GetConsoleScreenBufferInfo(out, &info);

    switch(mer.dwEventFlags)
    {
        case 0:
            for(int i = 0; i < AMOUNT_OF_ITEMS; i++)
            {
                if(mousePos.Y == item_list[i].getTop() && mousePos.X == 1){
                    SetConsoleCursorPosition(out, mousePos);
                    printf("X");
                    SetConsoleCursorPosition(out, info.dwCursorPosition);
                    return;
                }
            } 
            break;
        case MOUSE_MOVED:
            break;
        default:
            for(int i = 0; i < AMOUNT_OF_ITEMS; i++)
            {
                if(mousePos.Y == item_list[i].getTop() && mousePos.X == 1){
                    SetConsoleCursorPosition(out, mousePos);
                    printf("X");
                    SetConsoleCursorPosition(out, info.dwCursorPosition);
                    return;
                }
            } 
            break;
    }
}