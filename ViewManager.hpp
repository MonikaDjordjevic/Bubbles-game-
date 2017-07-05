

#ifndef ViewManager_hpp
#define ViewManager_hpp
#include"View.hpp"


class ViewManager {
View* currentView; // polimorfizm dziala tylko przez pointer(gwiazdke)
public:
    ViewManager();
    void run(Console* console);
    void switchView(View* view);
};


#endif /* ViewManager_hpp */
