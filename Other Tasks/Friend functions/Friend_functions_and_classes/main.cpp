#include <iostream>
#include "friend_functions.h"

using namespace std;

int main()
{
	Date d1(15, 9, 1999);
	Date d2;
	cout << "Enter the date.\n";
	cin >> d2;
	cout << "\nYou've entered:\n";
	cout << d2 << endl << endl;

	student s1;
	cout << "Enter data of the student.\n";
	cin >> s1;
	cout << endl << "Data of the student you've entered.\n\n";
	cout << s1 << endl;
	
	vectorC vec;
	int size = 0;
	cout << "\nEnter the size of vector:\n";
	cin >> size;
	for (int i = 0; i < size; i++) {
		cout << "Enter value: ";
		cin >> vec;
	}
	cout << "\nValues in vector: " << vec << endl << endl;
	
	mString str;
	cout << "Enter new string: ";
	cin >> str;
	cout << "\nString you've entered: " << str << endl << endl;
	

	groupOfStudents groupA;
	cout << "Enter data of the first student." << endl;
	cin >> groupA;

	cout << "\nEnter data of the second student." << endl;
	cin >> groupA;

	cout << "\nData of all students in group A." << endl;
	cout << groupA;
}	