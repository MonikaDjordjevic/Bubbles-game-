#include <iostream>
#include "GameState.hpp"
#include "MacConsole.hpp"
#include "Game.hpp"
#include "Menu.hpp"
#include "ViewManager.hpp"


#include <iostream>
#include "GameState.hpp"
#include "MacConsole.hpp"
#include "Game.hpp"
#include "Menu.hpp"
#include "ViewManager.hpp"

template<class Console>
void startGame(){
    srand((int) time(NULL));
    Console console;
    ViewManager viewManager;
    viewManager.switchView(new Menu);
    viewManager.run(&console);
}


int main(int argc, const char * argv[]) {
    startGame<MacConsole>();
    return 0;
}

    
    
    
    
    
    
    
    
    
    
    
    
