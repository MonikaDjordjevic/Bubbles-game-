
#include "ViewManager.hpp"

ViewManager::ViewManager(): currentView(nullptr) {}
void ViewManager::run(Console* console) {
    while(currentView != nullptr) {
        currentView->draw(console);
        currentView->update(this);
    }
}

void ViewManager::switchView(View* view) {
    delete currentView;  // delete jak dostanie null to nic nie robi, tu zwalniam pamiec i dzieki temu nie ma wyciekow
    currentView = view;
}

