#include "Game.hpp"
#include "ViewManager.hpp"
#include "Menu.hpp"
#include "Dfs.hpp"
#include "GameOver.hpp"
#include<iostream>
using namespace std;


int countBlank (GameState &gameState) {
    int counter = 0;
    for (int i = 0; i < gameState.getHeight(); i++){
        for (int j = 0; j < gameState.getWidth(); j++) {
            if(gameState.getField(j, i) == BLANK) {
                counter++;
            }
        }
    }
    return counter;
}



bool checkifballs (GameState &gameState, int x, int y) {
    if (gameState.getField(x, y) == BLANK) {
        return true;
    } else {
        return false;
    }
    
}




void addingballs (GameState &gameState) {
    int placedBalls = (int)gameState.getFutureBalls().size();
    while(placedBalls){
        int x;
        int y;
        x = rand()%(gameState.getWidth());     //losowanie pola na kulke
        y = rand()%(gameState.getHeight());
    // zrob sobie potem oddzielna funkcje zeby sprawdzac warunek ze jesli juz jest kulka w tym miejscu to losuj kolejne liczby jesli nie ma to wstaw w to miejsce
    
        if(checkifballs(gameState, x, y)){
            placedBalls--;
            gameState.setField(x, y, gameState.getFutureBalls()[placedBalls]);
        }
    }
    gameState.setFutureBalls(gameState.createFutureBalls());
}



void checkBallsInLine (GameState & gameState, int x, int y, int dx, int dy) {
    int cx = x;
    int cy = y;
    int counter = 0;
    if (gameState.getField(x, y) == BLANK) {
        return;
    }
    while(gameState.getField(cx, cy) == gameState.getField(x, y)){
        cx += dx;
        cy += dy;
        counter++;
    }
    cx = x;
    cy = y;
    if(counter >= 5) {
        for(int i = 0; i < counter; i++) {
            gameState.setField(cx, cy, BLANK);
            cx += dx;
            cy += dy;
        }
        gameState.addPoints(counter);
    }
}


void checkLinesFromPoint (GameState & gameState, int x, int y) {
    checkBallsInLine(gameState, x, y, 0, 1);  // w dol
    checkBallsInLine(gameState, x, y, 1, 0); // w prawo
    checkBallsInLine(gameState, x, y, 1, 1); // na ukos
}

void checkLines (GameState &gameState) {
    for (int i = 0; i < gameState.getHeight(); i++){
        for (int j = 0; j < gameState.getWidth(); j++) {
            checkLinesFromPoint(gameState, j, i);
        }
    }
}

Game::Game () {
    addingballs(gameState);    //dodaje poczatkowe kulki
}

Game::Game (const char* file) {
    gameState.load(file);
}

void Game::start() {

}

void Game::update(ViewManager* viewManager) {
    //ze stackoverflow
    int x1, y1, x2, y2;
    while(true) {                 // continue i break dziala jak goto continue wraca od poczatku robi kolejny obrot a break wychodzi z petli
        std::cout << "Podaj wspolrzedne skad chcesz sie przesunac (od 0 do 9)\n";
        if(!(std::cin >> x1 >> y1 )){
            std::cin.clear(); //clear bad input flag
            string wyj;
            std::cin >> wyj;
            if(wyj != "q") {
            std::cout << "Niepoprawna liczba.\n";
                continue;
            }
            gameState.save("game.txt");
            viewManager->switchView(new Menu);
            return;
        }
        if(x1 >= gameState.getWidth() || y1 >= gameState.getHeight() || x1<0 || y1<0) {
            cout << "Punkty poza plansza";
            continue;
        }
        if(gameState.getField(x1, y1) == BLANK) {
            cout << "Na tym polu nie ma kulki";
            continue;
        }
        break;
    }
    while(true) {
        std::cout << "Podaj wspolrzedne gdzie chcesz sie przesunac (od 0 do 9) \n";
        if(!(std::cin >> x2 >> y2 )){
            std::cin.clear(); //clear bad input flag
            string wyj;
            std::cin >> wyj;
            if(wyj != "q") {
                std::cout << "Niepoprawna liczba.\n";
                continue;
            }
            gameState.save("game.txt");
            viewManager->switchView(new Menu);
            return;
        }
        if(x2 >= gameState.getWidth() || y2 >= gameState.getHeight() || x2<0 || y2<0) {
            cout << "Punkty poza plansza \n";
            continue;
        }

        Dfs dfs(&gameState);
        dfs.dfs(x1,y1);
        if(!dfs.isVisited(x2, y2)) {
            cout << "Nie mozesz tam sie przesunac \n";
            continue;
        }
        move(x1, y1, x2, y2);
        break;
    }
    int counter = countBlank(gameState);
    if(counter < (gameState.getFutureBalls().size() + 1)) {
        viewManager->switchView(new GameOver(gameState.getPoints()));
        return;
    }
    addingballs(gameState);
}


void Game::draw(Console* console) {    //przez pointer przekazuje zeby dzialal polimorfizm, tutaj rysowanie
    
    vector<Colour> futureColours = gameState.getFutureBalls();
    for (int i = 0; i < gameState.getHeight(); i++){
        for (int j = 0; j < gameState.getWidth(); j++) {
            Colour colour = gameState.getField(j,i);
            console->setColour(colour);
            if(colour == BLANK) {
                console->print(".");
            } else {
                cout << colour;
            }
        }
        cout << endl;
    }
    console->setColour(BLANK);
    cout << "To są futurecolours :";
    for(int i = 0; i < futureColours.size(); i++) {
        console->setColour(futureColours[i]);
        cout << futureColours[i];
    }
    cout << endl;
    console->setColour(BLANK);
    cout << "Punkty :" << gameState.getPoints();
    cout << endl;
}



bool Game::move(int xs, int ys, int xd, int yd) {
    gameState.setField(xd, yd, gameState.getField(xs, ys));
    gameState.setField(xs, ys, BLANK);
    checkLines(gameState);
    return true;
}






