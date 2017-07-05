//
//  GameOver.cpp
//  kulki
//
//  Created by Monika on 08/06/17.
//  Copyright © 2017 Monika. All rights reserved.
//
#include "View.hpp"
#include "ViewManager.hpp"
#include "Menu.hpp"
#include "GameOver.hpp"
#include <string>
using namespace std;

void GameOver::update(ViewManager* viewManager) {
    std::string nazwa;
    cout << "Podaj imie" << endl;
    cin >> nazwa;
    FILE* stream;
    stream = fopen("Ranking.txt", "a");
    
    if (stream == NULL) { /* sprawdzamy, czy otwieranie się powiodło */
        std::cout << "Nie udalo sie otworzyc pliku do zapisu" << std::endl;
        return;
    }
    fprintf(stream, "%s %d \n", nazwa.c_str(), points);
    fclose(stream);
    viewManager->switchView(new Menu);      //nie wycieka tu pamiec bo w switchView zwalniam pamiec
}

void GameOver::draw(Console* console) {
    cout << "Game Over" << endl;
    cout << "Twoja ilosc punktow to: " << points << endl;
}