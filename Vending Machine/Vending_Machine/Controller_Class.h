#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <thread>
#include "Exception_Classes.h"
#define Vec vector<pair<double, string>>
#define Item pair<double, string>

using namespace std;

class Controller {

friend class Display;

private:
    static const string password;
    Vec PaymentsVec;
    double MoneySum = 0;
    Item p;
    Vec Items = {
        {2.50,"Coffee"},
        {1.50,"Black Tea"},
        {1.50,"Green Tea"},
        {2.00,"Cocoa"},
        {1.00,"Hot Water"},
        {3.00,"Chicken Soup"},
        {3.00,"Tomato Soup"},
        {3.00,"Borscht"},
        {3.50,"Miso Soup"},
        {3.00,"Onion Soup"}
    };
public:
    bool PaymentProcessing(Item p) 
    {
        cout << endl << "  Vending machine accepts only:  " << endl;
        cout << "  0.25$, 0.5$, 1$, 2$, 5$ coins. " << endl;
        cout << "  The machine gives the change.  " << endl << endl;
        double Rest = p.first;
        double Payment = 0;

        while (Rest > 0) {
            cout << "(Simulate not inserting coins in time by entering 0)" << endl;
            cout << " Insert coin : ";
            cin >> Payment;
            if (Payment != 0 && Payment != 0.25 && Payment != 0.5 && Payment != 1 && Payment != 2 && Payment != 5) 
            {
                throw InvalidPayment();
            }
            if (Payment == 0) {
                return false;
            }
            Rest = Rest - Payment;
        }

        MoneySum = MoneySum + p.first;
        PaymentsVec.push_back(p);

        if (Rest < 0) {
            cout << endl << "Giving change .";
            std::this_thread::sleep_for(500ms);
            cout << ".";
            std::this_thread::sleep_for(500ms);
            cout << "." << endl;
            std::this_thread::sleep_for(500ms);
            cout << endl << "Your change is " << -Rest << "$" << endl;
        }
        return true;
    }

    void SelectMOption(int mOption) 
    {
        char c;
        switch (mOption) 
        {
        case 1:
            for (auto k : PaymentsVec)
            {
                cout << k.first << " - " << k.second << endl;
            }
            cout << endl << "Returning to maintenance menu..." << endl;
            cout << "Press any key to continue." << endl;
            cin >> c;
            break;
        case 2:
            cout << endl << "Collected: " << MoneySum << "$" << endl << endl;
            cout << "Returning to maintenance menu..." << endl;
            cout << "Press any key to continue." << endl;
            cin >> c;
            MoneySum = 0;
            break;
        case 3:
            cout << "Vending Machine is shutting down .";
            std::this_thread::sleep_for(500ms);
            cout << ".";
            std::this_thread::sleep_for(500ms);
            cout << "." << endl;
            std::this_thread::sleep_for(500ms);
            exit(0);
            break;
        case 4:
            break;
        }
    }

    Item SelectBev(int Option)
    {
        return Items[Option - 1];
    }
};

const string Controller::password = "HardPassword";