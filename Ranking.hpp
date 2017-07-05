

#ifndef Ranking_hpp
#define Ranking_hpp
#include "View.hpp"
#include <stdio.h>

class Ranking: public View {
public:
    Ranking() {};
    virtual ~Ranking() {}
    virtual void update(ViewManager* viewManager);
    virtual void draw(Console* console);
    
};


#endif /* Ranking_hpp */
