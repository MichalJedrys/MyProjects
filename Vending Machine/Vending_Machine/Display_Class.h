#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include "Exception_Classes.h"
#include "Controller_Class.h"

using namespace std;

class Display {
private:
    int Option;
public:
    void Start() {
        cout << "Vending Machine is starting .";
        std::this_thread::sleep_for(500ms);
        cout << ".";
        std::this_thread::sleep_for(500ms);
        cout << "." << endl;
        std::this_thread::sleep_for(500ms);
    }

    int MainMenu() 
    {
        cout << " " << endl;
        cout << "Available options:" << endl;
        cout << " 1. Coffee          2.50$ " << endl;
        cout << " 2. Black Tea       1.50$ " << endl;
        cout << " 3. Green Tea       1.50$ " << endl;
        cout << " 4. Cocoa           2.00$ " << endl;
        cout << " 5. Hot Water       1.00$ " << endl;
        cout << " 6. Chicken Soup    3.00$ " << endl;
        cout << " 7. Tomato Soup     3.00$ " << endl;
        cout << " 8. Borscht         3.00$ " << endl;
        cout << " 9. Miso Soup       3.50$ " << endl;
        cout << "10. Onion Soup      3.00$ " << endl;
        cout << "11. Maintenance mode      " << endl;
        cout << " " << endl;
        cout << "Pick an option: ";
        cin >> Option;
        if (Option <= 0 || Option > 11) 
        {
            throw IncorrectOption();
        }
        return Option;
    }

    int MaintenanceMenu() {
        string pass;
        cout << "Enter a password: ";
        cin >> pass;
        if (pass == Controller::password) 
        {
            cout << endl << "     Maintenance MENU     " << endl;
            cout << "1. History of transactions" << endl;
            cout << "2. Money withdraw         " << endl;
            cout << "3. Turn off the machine   " << endl;
            cout << "4. Return to main menu    " << endl << endl;
            cout << "Pick an option: ";
            cin >> Option;
            if (Option <= 0 || Option > 4) {
                throw IncorrectMTOption();
            }
            return Option;
        }
        else 
        {
            cout << "\nWrong password. Exiting to main menu..." << endl;
            return 0;
        }
    }

    void PrepDisp(Item p) {
        cout << endl << "Preparing " << p.second << ".";
        std::this_thread::sleep_for(500ms);
        cout << ".";
        std::this_thread::sleep_for(500ms);
        cout << ".";
        std::this_thread::sleep_for(500ms);
        cout << ".";
        std::this_thread::sleep_for(500ms);
        cout << "." << endl;
        std::this_thread::sleep_for(500ms);
        cout << endl << p.second << " is ready." << endl;
        std::this_thread::sleep_for(2000ms);
    }
};