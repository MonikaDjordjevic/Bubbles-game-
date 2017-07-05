/*#include "WindowsConsole.hpp"
#include<iostream>
#include<windows.h>
using namespace std;


void WindowsConsole::setColour(Colour col) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    
    
    switch (col) {
        case BLANK:
            SetConsoleTextAttribute(hConsole, 7);
            break;
        case RED:
            SetConsoleTextAttribute(hConsole, 4);
            break;
        case BLUE:
            SetConsoleTextAttribute(hConsole, 1);
            break;
        case GREEN:
            SetConsoleTextAttribute(hConsole, 2);
            break;
        case YELLOW:
            SetConsoleTextAttribute(hConsole, 6);
            break;
        case MAGENTA:
            SetConsoleTextAttribute(hConsole, 5);
            break;
        case CYAN:
            SetConsoleTextAttribute(hConsole, 9);
            break;
        case WHITE:
            SetConsoleTextAttribute(hConsole, 7);
            break;
    }
}

void WindowsConsole::print(const char* w) {
    cout << w;
}

void WindowsConsole::cleanscreen() {
    cout << "\x1B[2J\x1B[H";
} */