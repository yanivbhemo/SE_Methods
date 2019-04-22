#include <windows.h>
#include "label.h"
#include "checkbox.h"

#define AMOUNT_OF_ITEMS 5

void HandleClick(int item_list[]);
void MouseEventProc(MOUSE_EVENT_RECORD mer, int item_list[]);

int main(int argc, char** argv){
    Label l;
    int label1_left = 0, label1_top = 0;
    Checkbox c1,c2;
    int c1_left = label1_left, c1_top = label1_top+1;
    int c2_left = label1_left, c2_top = c1_top+1;
    int item_list [AMOUNT_OF_ITEMS];

    l.setText("Hello Checkbox");
    l.setPosition(label1_left, label1_top);
    l.draw();
    c1.setText("Option 1");
    c1.setPosition(c1_left, c1_top);
    c1.draw();
    item_list[0] = c1_top;
    c2.setText("Option 2");
    c2.setPosition(c2_left, c2_top);
    c2.draw();
    item_list[1] = c2_top;
    while(true){
        HandleClick(item_list);
    }
    return 0;
}

void HandleClick(int item_list[])
{
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD cNumRead, i, fdwMode, fdwSaveOldMode;
    INPUT_RECORD irInBuf[128]; 

    GetConsoleMode(hStdin, &fdwSaveOldMode);
    
    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT; 
    SetConsoleMode(hStdin, fdwMode);
    while(true){
        ReadConsoleInput( 
                    hStdin,      // input buffer handle 
                    irInBuf,     // buffer to read into 
                    128,         // size of read buffer 
                    &cNumRead); // number of records read 
        if(irInBuf[0].EventType == MOUSE_EVENT) 
        { 
            MouseEventProc(irInBuf[0].Event.MouseEvent, item_list); 
        }
    }
}

void MouseEventProc(MOUSE_EVENT_RECORD mer, int item_list[])
{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
    COORD mousePos = mer.dwMousePosition;
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);

    switch(mer.dwEventFlags)
    {
        case 0:
            for(int i = 0; i < AMOUNT_OF_ITEMS; i++)
            {
                if(mousePos.Y == item_list[i] && mousePos.X == 1){
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
                if(mousePos.Y == item_list[i] && mousePos.X == 1){
                    SetConsoleCursorPosition(out, mousePos);
                    printf("X");
                    SetConsoleCursorPosition(out, info.dwCursorPosition);
                    return;
                }
            } 
            break;
    }
}