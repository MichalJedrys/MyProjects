#include <iostream>
#include <string>
#include "Matrix_Template.h"

int main()
{
	Matrix <int> M1(2, 3), M2(2, 3), M3(2, 3), M4(2, 3), M5(2, 3), M6(2, 3);
	Matrix <double> M1d(3, 3), M2d(3, 3);
	Matrix <char> M1c(1, 3);
	Matrix <std::string> M1s(2, 2), M2s(2, 2), M3s(2, 2);

	Matrix <int> M10(5, 3), M11(3, 4), M12(3, 3);

	std::cout << "Fill matrix M1 with 'int':\n";
	M1.fill();
	std::cout << "Fill matrix M2  with 'int':\n";
	M2.fill();
	std::cout << "Fill matrix M1c with 'char':\n";
	M1c.fill();
	std::cout << "Fill matrix M1s with 'string':\n";
	M1s.fill();
	std::cout << "Fill matrix M2s with 'string':\n";
	M2s.fill();
	std::cout << "Fill matrix M1d with 'double':\n";
	M1d.fill();

	std::cout << "\nFirst element in second row of the martix M1 is " << M1(1, 0) << ".\n\n";

	M3.fill_random(0, 10);

	std::cout << "Randomly filled matrix M3 with 'int':\n";
	M3.display();

	M3 = M2 + M1;
	M4 = M1 - 5;
	std::cout << "\nMatrix M3 = M2 + M1:\n";
	M3.display();
	std::cout << "\nMatrix M4 = M1 - 5:\n";
	M4.display();

	M3s = M1s + M2s;
	std::cout << "\nMatrix M3s = M1s + M2s:\n";
	M3s.display();

	M2d = M1d / 2;
	std::cout << "\nMatrix M2d = M1d / 2:\n";
	M2d.display();

	M10.fill_random(0, 10);
	M11.fill_random(0, 10);

	std::cout << "\nM1:\n";
	M10.display();
	std::cout << "\nM2:\n";
	M11.display();

	M12 = M10 * M11;
	std::cout << "\nMatrix M12 = M10 * M11:\n";
	M12.display();

	std::cout << "\nMax value of matrix M12 is :" << M12.max() << "\n\n";
	std::cout << "\nMin value of matrix M12 is :" << M12.min() << "\n";
}