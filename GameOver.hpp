//
//  GameOver.hpp
//  kulki
//
//  Created by Monika on 08/06/17.
//  Copyright © 2017 Monika. All rights reserved.
//

#ifndef GameOver_hpp
#define GameOver_hpp

#include "View.hpp"
#include <stdio.h>

class GameOver: public View {
    int points;
public:
    GameOver(int points): points(points) {};
    virtual ~GameOver() {}
    virtual void update(ViewManager* viewManager);
    virtual void draw(Console* console);
    
};


#endif /* GameOver_hpp */
