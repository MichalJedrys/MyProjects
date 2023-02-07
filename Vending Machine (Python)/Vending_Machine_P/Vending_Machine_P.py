from Feeder_Class import FeederDrink, FeeederSoup
from Display_Class import Display
from Controller_Class import Controller

class VendingMachine(Display,Controller,FeederDrink, FeeederSoup):

    def work(self):
        try:
            __option = -1
            __moption = -1
            __product = ()
            __option = super().MainMenu(super().Menu_Items)
            if __option == 11:
                __moption = super().MaintenanceMenu()
                if __moption == 0: 
                    return
                else:
                    super().SelectMOption(__moption)
            else:
                __product = super().SelectBev(__option)
                if super().PaymentProcessing(__product):
                    if __option < 6:
                        super().MilkAndSugar(__option)
                    else:
                        super().SoySauce()
                    super().PrepDisp(__product)
        except Exception as error:
            print("Error: " +  repr(error))
        except:
            print("Ops, something went wrong. Try again")


#main code
Machine = VendingMachine()
Machine.Start()
while True:
    Machine.work()