#ifndef GameState_h
#define GameState_h
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <string>

enum Colour {BLANK, RED, BLUE, YELLOW, GREEN, CYAN, MAGENTA, WHITE, NUM_COLOURS}; // kolorowy w domysle od 0 itp
class GameState {
    
    
    std::vector<std::vector<Colour>> board;
    std::vector<Colour> futureBalls;
    int points;
    int width;
    int height;
public:
    GameState();
    
    Colour getField (int x, int y);
    
    void setField (int x, int y, Colour colour);
    
    std::vector<Colour> getFutureBalls ();
    
    void setFutureBalls (std::vector<Colour> balls);
    
    int getPoints ();
    
    void addPoints (int reward);
    
    int getWidth ();
    
    int getHeight ();
    
    std::vector<std::vector<Colour>> createBoard(int x, int y);
    
    std::vector<Colour> createFutureBalls ();
    
    Colour randomBall();
    
    void save(const char* fileName);
    
    void load(const char* fileName);
};




#endif /* GameState_h */
