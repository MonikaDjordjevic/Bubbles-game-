

#ifndef View_hpp
#define View_hpp
#include "Console.hpp"
class ViewManager;   // tylko mu mowie ze takie cos bedzie

class View {
public:
    virtual ~View() {}  // musi byc wirtualny poniewaz delete uzywam na nadklasie i kazda musi inaczej go implementowac
    virtual void update(ViewManager* viewManager) = 0;   //pure virtual bo nie ma implenetacji
    virtual void draw(Console* console) = 0;


};

#endif /* View_hpp */
