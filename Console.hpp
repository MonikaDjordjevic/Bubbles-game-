
#ifndef Console_hpp
#define Console_hpp
#include "GameState.hpp"
#include <stdio.h>
class Console {
public:
    virtual void setColour(Colour col) = 0;
    virtual void print(const char* w) = 0;
    virtual void cleanscreen() = 0;    // =0 to nie bedzie implementacji

};






#endif /* Console_hpp */
