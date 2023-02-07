import time

class Controller():
    password = "HardPassword"
    __MoneySum = 0
    __PaymentHistory = []

    Menu_Items = (
            (2.50,"Coffee"),
            (1.50,"Black Tea"),
            (1.50,"Green Tea"),
            (2.00,"Cocoa"),
            (1.00,"Hot Water"),
            (3.00,"Chicken Soup"),
            (3.00,"Tomato Soup"),
            (3.00,"Borscht"),
            (3.50,"Miso Soup"),
            (3.00,"Onion Soup"))

    def PaymentProcessing(self,item):
        print("""\n  Vending machine accepts only:  \n
                    0.25$, 0.5$, 1$, 2$, 5$ coins.  \n
                    The machine gives change.  \n""")
        rest = item[0]
        payment = 0
        while rest > 0:
            print('(Simulate not inserting coins in time by entering 0)')
            payment_str = input("Insert coin: ")
            payment = int(payment_str)
            if payment != 0 and payment != 0.25 and payment != 0.5 and payment != 1 and payment != 2 and payment != 5:
                raise ValueError("Incorrect input. Please try again.")
            if payment == 0:
                return False
            rest-=payment
        Controller.__MoneySum+=item[0]
        Controller.__PaymentHistory.append(item)
        if rest < 0:
            print('\nGiving change .',end=''); time.sleep(0.5)
            print('.',end=''); time.sleep(0.5)
            print('.'); time.sleep(0.5)
            print('\nYour change is ' , -rest , '$')
        return True

    def SelectMOption(self,mopt):
        match mopt:
            case 1:
                for x in Controller.__PaymentHistory:
                    print(x[0] ,' - ', x[1])
                print('\nReturning to maintenance menu...')
                input('Press any key to continue.')
            case 2:
                print('\nCollected: ', Controller.MoneySum ,'$\n\nReturning to maintenance menu...')
                input('Press any key to continue.')
                Controller.MoneySum = 0
            case 3:
                print('Vending Machine is shutting down .',end=''); time.sleep(0.5)
                print('.',end=''); time.sleep(0.5)
                print('.'); time.sleep(0.5)
                exit(0)
            case 4:
                pass

    def SelectBev(self,option):
        return Controller.Menu_Items[option-1]