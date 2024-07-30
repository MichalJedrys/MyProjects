#include "VendingMachine.hpp"

void VendingMachine::work()
{
    Option = -1;
    mOption = -1;
    try
    {
        Option = MainMenu();
    }
    catch (const IncorrectOption& ex)
    {
        std::cout << "\nError: " << ex.what() << std::endl;
        return;
    }
    
    if (Option == 11) {
        try
        {
            mOption = MaintenanceMenu();
        }
        catch (const IncorrectMTOption& ex)
        {
            std::cout << "\nError: " << ex.what() << std::endl;
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
                        std::cout << "\nError: " << ex.what() << std::endl;
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
                        std::cout << "\nError: " << ex.what() << std::endl;
                        return;
                    }
                }
                PrepDisp(product);
            }
        }
        catch (const InvalidPayment& ex)
        {
            std::cout << "\nError: " << ex.what() << std::endl;
            return;
        }
    }
}