#include "Copy-Array.h"
#include "Copy-Array-Into-Two-Arrays.h"
#include "Merging-Arrays.h"
#include "Merging-Arrays-Sequencially.h"
#include "Reverse-Array.h"
#include "Swap-Arrays.h"

int main()
{
	std::cout << "Copy Array.\n";
	copyArray();

	std::cout << "\nCopy Array Into Two Arrays.\n";
	copyArrayIntoTwo();

	std::cout << "\nMerge Arrays.\n";
	mergeArray();

	std::cout << "\nMerge Arrays Sequencially.\n";
	meargeArraySeq();

	std::cout << "\nReverse Array.\n";
	reverseArray();

	std::cout << "\nSwap Array.\n";
	swapArray();
}