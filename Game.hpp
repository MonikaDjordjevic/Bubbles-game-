#ifndef Game_hpp
#define Game_hpp
#include <stdio.h>
#include "GameState.hpp"
#include "Console.hpp"
#include "View.hpp"

class Game: public View {
public:
    GameState gameState;
public:
    void start();
    Game ();
    Game (const char* file);
    virtual ~Game() {}
    virtual void update(ViewManager* viewManager); // bo dziedzicza z klasy ktora ma te metody virtual i dzieki temu wie ze to jest to samo
    virtual void draw(Console* console);
    bool move(int xs, int ys, int xd, int yd);
};







#endif /* Game_hpp */
