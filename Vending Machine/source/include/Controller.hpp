#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Exceptions.hpp"
#include <string>
#include <vector>
#include <chrono>
#include <iostream>
#include <thread>

#define item std::pair<double, std::string>

class Controller {
public:
    bool PaymentProcessing(item p);

    void SelectMOption(int mOption);

    item SelectBev(int Option);

    friend class Display;

private:
    inline static const std::string password = "HardPassword";

    std::vector<item> PaymentsVec;

    double MoneySum = 0;

    item p;
    
    std::vector<item> Items = {
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
};

#endif // CONTROLLER_HPP