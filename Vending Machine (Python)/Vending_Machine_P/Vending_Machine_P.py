from Feeder_Class import FeederDrink,FeeederSoup
from Display_Class import Display
from Controller_Class import Controller

class VendingMachine(Display,Controller,FeederDrink,FeeederSoup):

    def __init__(self):
            self.__option = -1
            self.__moption = -1
            self.__product = ()
            super().__init__()

    def work(self):
        self.__option = super().MainMenu(super().GetMenu())
        if self.__option == 11:
            self.__moption = super().MaintenanceMenu(super().GetPassword())
            if self.__moption == 0: 
                return
            else:
                super().SelectMOption(self.__moption)
        else:
            self.__product = super().SelectBev(self.__option)
            if super().PaymentProcessing(self.__product):
                if self.__option < 6:
                    super().MilkAndSugar(self.__option)
                else:
                    super().SoySauce()
                super().PrepDisp(self.__product)



#main code
Machine = VendingMachine()
Machine.Start()
while True:
    try:
        Machine.work()
    except ValueError as error:
        print("Error: Invalid input value. Please try again.")
    except:
        print("Ops, something went wrong. Try again")
        quit()
