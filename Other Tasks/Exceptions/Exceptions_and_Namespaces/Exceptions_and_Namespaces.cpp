#pragma warning(disable: 4290)

#include <iostream>
#include <exception>
#include "Ex_Classes.h"
#include "../../Task 01/Memory_management/Memory_management/Copy-Array.h"
#include "../../Task 01/Memory_management/Memory_management/Copy-Array-Into-Two-Arrays.h"
#include "../../Task 01/Memory_management/Memory_management/Merging-Arrays-Sequencially.h"
#include "../../Task 01/Memory_management/Memory_management/Merging-Arrays.h"
#include "../../Task 02/STL-Tasks/real_file.h"
#include "../../Task 02/STL-Tasks/string_analyzer.h"
using namespace std;

#include "Classes.h"
using namespace st_gr;
using namespace shp;


int main()
{
	//NAMESPACES TEST
	cout << "Start of the namespaces test.\n\n";
	triangle T1(10);
	cout << "Area of T1 triangle is: " << T1.area() << endl;
	triangle T2(3, 4, 5);
	cout << "Area of T2 triangle is: " << T2.area() << endl;
	triangle T3(6, 3);
	cout << "Area of T3 triangle is: " << T3.area() << endl;

	square S1(4);
	cout << "Area of S1 square is: " << S1.area() << endl;

	cout << endl;

	groupOfStudents GroupA;
	GroupA.addStudent("Tom", 21, "Male", 540673777);
	GroupA.addStudent("Mark", 20, "Male", 757333234);
	GroupA.addStudent("Joanna", 22, "Female", 656098153);
	GroupA.printInfo("Tom");

	cout << endl;
	cnt::vectorC vec;
	vec.push(1);
	vec.push(2);
	vec.push(3);
	vec.push(4);
	vec.push(5);
	cout << "Vector: ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.get(i) << " ";
	}
	cout << endl;
	cout << "\nEnd of the namespaces test.\n\n";

	//EXCEPTIONS
	try
	{
		copyArray();
	}
	catch (const outOfRange& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}

	try
	{
		string_analyzer r_file(new real_file());

		string Output;
		r_file.config_f(Output, "Config_Output.txt");

		for (auto k : Output) {
			std::cout << k;
		}
		std::cout << "\n";
	}
	catch (const noFile& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}

	try
	{
		int a = 5;
		int b = 0;
		if (b == 0) { throw devideByZero(); }
		cout << "Result of operation: " << a / b << endl;
	}
	catch (const devideByZero& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}

	try
	{
		int res;
		int a=1700000000;
		int b=2000000000;

		res = a + b;
		if ((a>0 && b>0 && res <0) || (a<0 && b<0 && res >0)) { throw intOverflow(); }
		cout << "Result of operation: " << res << endl;
	}
	catch (const intOverflow& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}

	try
	{
		int i;
		vector<int>vec = { 0,1,2,3,4,5,6,7,8,9 };
		cout << "Which element would you like to print?\n";
		cin >> i;
		if (i >= vec.size()) { throw invalidIndex(); }
		cout << "Searched element is: " << vec[i] << endl;
	}
	catch (const invalidIndex& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}
	
	try
	{
		copyArrayIntoTwo();
		meargeArraySeq();
		mergeArray();
	}
	catch (const notEvenNumber& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}
}
