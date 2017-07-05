#include "GameState.hpp"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <string>


GameState::GameState() {                                  // konstruktor domyślny
    width = 9;
    height = 9;
    this->board = createBoard(width, height);
    this->futureBalls = createFutureBalls();
    this->points = 0;
}

Colour GameState::getField (int x, int y) {
    if (x < getWidth() && y < getHeight() && x>=0 && y>=0) {
        return board[x][y];
    } else {
        return BLANK;
    }
}

void GameState::setField (int x, int y, Colour colour) {
    board[x][y] = colour;
}

std::vector<Colour> GameState::getFutureBalls () {
    return futureBalls;
}

void GameState::setFutureBalls (std::vector<Colour> balls) {
    futureBalls = balls;
}

int GameState::getPoints () {
    return points;
}

void GameState::addPoints (int reward) {
    points += reward;
}

int GameState::getWidth () {
    return width;
}

int GameState::getHeight () {
    return height;
}



std::vector<std::vector<Colour>> GameState::createBoard(int x, int y) {
    std::vector<std::vector<Colour>> board;
    
    for(int i = 0; i < x; i++) {
        board.push_back(std::vector<Colour>());      // tworze obiekt typu std::vector<Colour>
        for(int j = 0; j < y; j++) {
            board.back().push_back(BLANK);   //back() daje ostatni element
        }
    }
    return board;
}


std::vector<Colour> GameState::createFutureBalls () {
    std::vector<Colour> futureBalls;
    for(int i = 0; i < 3; i++) {
        futureBalls.push_back(randomBall());
    }
    return futureBalls;
}

Colour GameState::randomBall() {
    return static_cast<Colour>(1 + (rand()%(NUM_COLOURS - 1)));  // losowanie i rzutuowanie inta na colour
}

void GameState::save(const char* fileName){
    FILE* stream;
    stream = fopen(fileName, "w");
    
    if (stream == NULL) { /* sprawdzamy, czy otwieranie się powiodło */
        std::cout << "Nie udalo sie otworzyc pliku do zapisu" << std::endl;
        return;
    }
    fprintf(stream, "%d %d\n", width, height );
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            fprintf(stream, "%d ",getField(j, i));
        }
        fprintf(stream, "\n");
    }
    fprintf(stream, "%d \n", (int)futureBalls.size());
    for(int i = 0; i < (int)futureBalls.size(); i++) {
        fprintf(stream, "%d ", futureBalls[i]);
    }
    fprintf(stream, "\n");
    fprintf(stream, "%d \n", points);
    fclose(stream);
}

void GameState::load(const char* fileName){
    FILE* stream;
    stream = fopen(fileName, "r");
    
    if (stream == NULL) { /* sprawdzamy, czy otwieranie się powiodło */
        std::cout << "Nie udalo sie otworzyc pliku do odczytu" << std::endl;
        return;
    }
    fscanf(stream, "%d %d", &width, &height );
    this->board = createBoard(width, height);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            Colour colour;
            fscanf(stream, "%d ", &colour);
            setField(j, i, colour);
        }
    }
    int amount;
    fscanf(stream, "%d", &amount);
    futureBalls.clear();
    for(int i = 0; i < amount; i++) {
        Colour colour;
        fscanf(stream, "%d ", &colour);
        futureBalls.push_back(colour);
    }
    fscanf(stream, "%d \n", &points);
    fclose(stream);
}

