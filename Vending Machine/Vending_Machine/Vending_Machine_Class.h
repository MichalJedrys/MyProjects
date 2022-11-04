#pragma once
#include "Controller_Class.h"
#include "Display_Class.h"
#include "Feeder_Class.h"

class VendingMachine : public Controller, public Display, public FeederDrink, public FeederSoup {
private:
    int Option;
    int mOption;
    Item product;
public:
    void work()
    {
        Option = -1;
        mOption = -1;
        try
        {
            Option = MainMenu();
        }
        catch (const IncorrectOption& ex)
        {
            cout << "\nError: " << ex.what() << endl;
            return;
        }
      
        if (Option == 11) {
            try
            {
                mOption = MaintenanceMenu();
            }
            catch (const IncorrectMTOption& ex)
            {
                cout << "\nError: " << ex.what() << endl;
                return;
            }
            if (mOption == 0) {
                return;
            }
            else {
                SelectMOption(mOption);
                return;
            }
        }
        else{
            product = SelectBev(Option);
            try
            {
                if (PaymentProcessing(product))
                {
                    if (Option <= 5) {
                        try
                        {
                            MilkAndSugar(Option);
                        }
                        catch (const InvalidOperator& ex)
                        {
                            cout << "\nError: " << ex.what() << endl;
                            return;
                        }
                    }
                    else {
                        try
                        {
                            SoySauce();
                        }
                        catch (const InvalidOperator& ex)
                        {
                            cout << "\nError: " << ex.what() << endl;
                            return;
                        }
                    }
                    PrepDisp(product);
                }
            }
            catch (const InvalidPayment& ex)
            {
                cout << "\nError: " << ex.what() << endl;
                return;
            }
        }
        return;
    }
};