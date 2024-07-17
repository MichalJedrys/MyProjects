#include "Vending_Machine_Class.h"

int main()
{
	VendingMachine Machine;
	Machine.Start();
	while (1)
	{
		Machine.work();
	}
}
