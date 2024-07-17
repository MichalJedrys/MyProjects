#pragma once
#include <iostream>
#include <vector>
#include "Exception_Classes.h"

using namespace std;

class FeederSoup{
public:
    void SoySauce() 
    {
        char s;
        cout << endl << "Do you want to add soy sauce? (y/n): ";
        cin >> s;
        if (s != 'y' && s != 'n') {
            throw InvalidOperator();
        }
    }
};

class FeederDrink{
public:
    void MilkAndSugar(int ID) {
        int sugar;
        char m;
        if (ID == 1) 
        {
            cout << "\nDo you want to add milk? (y/n): ";
            cin >> m;
            if (m != 'y' && m != 'n') {
                throw InvalidOperator();
            }
        }
        if (ID >= 1 && ID < 5) {
            cout << "\nSet amount of sugar you want (0-6): ";
            cin >> sugar;

            if (sugar < 0 || sugar>6) {
                throw InvalidOperator();
            }
        }
    }
};