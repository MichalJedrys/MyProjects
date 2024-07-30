#include "VendingMachine.hpp"

int main()
{
	VendingMachine Machine;
	Machine.Start();
	while (1)
	{
		Machine.work();
	}
}
