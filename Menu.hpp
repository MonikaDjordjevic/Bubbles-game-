#ifndef Menu_hpp
#define Menu_hpp
#include "Console.hpp"
#include "View.hpp"


class Menu: public View {
public:
    Menu() {};
    virtual ~Menu() {}
    virtual void update(ViewManager* viewManager);
    virtual void draw(Console* console);


};








#endif /* Menu_hpp */
