#include "Menu.hpp"
#include "ViewManager.hpp"
#include "Ranking.hpp"
#include "Game.hpp"
#include <iostream>
using namespace std;

void Menu::update(ViewManager* viewManager) {
    int wybor = -1;
    //ze stackoverflow
    cout << "W każdej z wybranej opcji możesz w dowolnym momencie kliknac q aby powrocic do menu" <<endl;
    while (std::cout << "Podaj swoj wybor \n" && !(std::cin >> wybor)) {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Niepoprawna liczba.\n";
    }
    
    switch(wybor) {
        case 1:
            viewManager->switchView(new Game);
            break;
        case 2:
            viewManager->switchView(new Game("game.txt"));
            break;
        case 3:
            viewManager->switchView(new Ranking);
            break;
        case 4:
            //wychodze z programu
            viewManager->switchView(nullptr);
            break;
        default:
            cout << "Niepoprawna liczba" << endl;
    }
}


void Menu::draw(Console* console) {
    cout << "1. NOWA GRA" << endl;
    cout << "2. Kontynuuj" << endl;
    cout << "3. RANKING" << endl;
    cout << "4. WYJDZ" << endl;
}