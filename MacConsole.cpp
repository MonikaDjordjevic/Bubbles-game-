#include "MacConsole.hpp"
#include<iostream>
using namespace std;
#define KBLA  "\x1B[30m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHI  "\x1B[37m"



void MacConsole::setColour(Colour col) {
    switch(col) {
        case BLANK:
            cout << KBLA;
            break;
        case RED :
            cout << KRED;
            break;
        case BLUE:
            cout << KBLU;
            break;
        case GREEN:
            cout << KGRN;
            break;
        case YELLOW:
            cout << KYEL;
            break;
        case MAGENTA:
            cout << KMAG;
            break;
        case CYAN:
            cout << KCYN;
            break;
        case WHITE:
            cout << KWHI;
            break;
    }
}

void MacConsole::print(const char* w) {
    cout << w ;
}

void MacConsole::cleanscreen() {
    cout << "\x1B[2J\x1B[H";
}