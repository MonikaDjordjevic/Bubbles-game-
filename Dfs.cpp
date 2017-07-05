

#include "Dfs.hpp"

Dfs::Dfs(GameState* gameState) {
    this->gameState = gameState;
    int x = gameState->getWidth();
    int y = gameState->getHeight();
    for(int i = 0; i < x; i++) {
        visited.push_back(std::vector<bool>());
        for(int j = 0; j < y; j++) {
            visited.back().push_back(false);
        }
    }
}


void Dfs::visit(int x, int y) {
    if(visited[x][y]){  //sprawdzam czy juz bylo odwiedzone
        return;
    }
    visited [x][y] = true;      //zaznaczam ze odwiedzam
    queuevisit(x+1, y);
    queuevisit(x, y+1);
    queuevisit(x-1, y);
    queuevisit(x, y-1);
}

void Dfs::queuevisit(int x,int y) {
    if(y>=gameState->getHeight() || x>=gameState->getWidth() || y<0 || x<0) {
        return;
    }
    if(gameState->getField(x, y) != BLANK) {
        return;
    }
    if(!visited [x][y]) {
        queue.push_back(std::make_pair(x, y));
    }
}

void Dfs::dfs(int x, int y) {    ///dostaje wspolrzedne poczatkowe a potem na visit moge sprawdzic czy poel na ktore chce sie przesunac jest true
    visit(x, y);
    while(!queue.empty()) {
        std::pair<int,int> para = queue.back();
        queue.pop_back();
        visit(para.first, para.second);
    }




}