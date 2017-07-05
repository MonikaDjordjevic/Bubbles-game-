//
//  Ranking.cpp
//  kulki
//
//  Created by Monika on 02/06/17.
//  Copyright © 2017 Monika. All rights reserved.
//

#include "Ranking.hpp"
#include "View.hpp"
#include<iostream>
#include <string>
#include<algorithm>
#include "ViewManager.hpp"
#include "Menu.hpp"
using namespace std;

void Ranking::update(ViewManager* viewManager) {
    cout << "Wcisnij q jesli chcesz powrocic do menu" << endl;
    string input;
    cin >> input;
    if(input == "q") {
        viewManager->switchView(new Menu);
    
    }

}

void Ranking::draw(Console* console) {
    cout << "RANKING" << endl;
    FILE* stream;
    stream = fopen("Ranking.txt", "r");
    
    if (stream == NULL) { /* sprawdzamy, czy otwieranie się powiodło */
        cout << "Ranking jest pusty" << endl;
        return;
    }
    
    vector<pair<int,string>> wyniki;
    
    while(!feof(stream)) {
        int wynik;
        char imie[100];
        
        int wczytane = fscanf(stream, "%99s%d", imie, &wynik);
        
        if (wczytane == -1) {
            break;
        }
        if (wczytane != 2) {
            cout << "Blad w pliku" << endl;
            fclose(stream);
            return;
        }
        
        wyniki.push_back(make_pair(wynik, string(imie))); // tu wkladam wynik do pary
    }
    fclose(stream);
    std::sort(wyniki.begin(), wyniki.end());
    
    for (int i = 0; i < wyniki.size(); i++) {
        cout << "* " << wyniki[i].second << " " << wyniki[i].first << endl;
    }
}

