/*#ifndef WindowsConsole_hpp
#ifdef WIN32
#define WindowsConsole_hpp
#include "Console.hpp"
#include <stdio.h>
#include<iostream>
#include<windows.h>
#include "GameState.hpp"

class WindowsConsole : public Console {
public:
    virtual void setColour(Colour col);
    virtual void print(const char* w);
    virtual void cleanscreen();
};



#endif
#endif /* WindowsConsole_hpp */
*/