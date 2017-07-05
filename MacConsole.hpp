

#ifndef MacConsole_hpp
#define MacConsole_hpp
#include "Console.hpp"
#include <stdio.h>

class MacConsole : public Console {
public:
    virtual void setColour(Colour col);
    virtual void print(const char* w);
    virtual void cleanscreen();
};




#endif /* MacConsole_hpp */
