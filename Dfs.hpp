
#ifndef Dfs_hpp
#define Dfs_hpp
#include <vector>
#include <stdio.h>
#include "GameState.hpp"

class Dfs {
    std::vector<std::vector<bool>> visited;   //tablica co bylo jzu odwiedzone
    std::vector<std::pair<int, int>> queue;
    GameState* gameState;
public:
    Dfs(GameState* gameState);
    void dfs(int x, int y);
    bool isVisited(int x, int y) {
        return visited[x][y];
    }
private:
    void visit(int x, int y);
    void queuevisit(int x,int y);
};
#endif /* Dfs_hpp */
