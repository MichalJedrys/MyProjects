#include <iostream>
#include "group_of_students_class.h"
#include "shape_class.h"
#include "student_class.h"
#include "vector_class.h"
#include "date_storage_class.h"
#include "string_class.h"

int main() 
{
	triangle T1(10);
	cout << "Area of T1 triangle is: " << T1.area() << endl;
	triangle T2(3,4,5);
	cout << "Area of T2 triangle is: " << T2.area() << endl;
	triangle T3(6, 3);
	cout << "Area of T3 triangle is: " << T3.area() << endl;

	square S1(4);
	cout << "Area of S1 square is: " << S1.area() << endl;
	
	cout << endl;
	
	groupOfStudents GroupA;
 	GroupA.addStudent("Tom", 21,"Male", 540673777);
	GroupA.addStudent("Mark", 20, "Male", 757333234);
	GroupA.addStudent("Joanna", 22, "Female", 656098153);
	GroupA.printInfo("Tom");

	cout << endl;
	vectorC vec;
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

	vectorC vec1, vec2, vec3, vec4;
	vec1.push(6);
	vec1.push(6);
	vec1.push(7);
	vec1.push(9);
	vec2.push(1);
	vec2.push(2);
	vec2.push(5);
	vec2.push(3);
	vec3 = vec1 + vec2;
	vec4 = vec1 - vec2;

	cout << "Result of adding:\n";
	for (int i = 0; i < vec3.size(); i++)
	{
		cout << vec3.get(i) << " ";
	}

	cout << endl << "Result of subtraction:\n";
	for (int i = 0; i < vec4.size(); i++)
	{
		cout << vec4.get(i) << " ";
	}
	cout << endl << endl;

	student Tom, AnotherTom;
	Tom.setName("Tom");
	Tom.setAge(22);
	Tom.setGender("Male");
	Tom.setPhoneNr(768543998);

	AnotherTom = Tom;
	cout << "Another Tom's phone number is: " << Tom.getPhoneNr() << ".\n";

	groupOfStudents GroupB, GroupC;
	GroupB.addStudent("Tom", 22, "Male", 768'543'998);
	GroupB.addStudent("Mark", 21, "Male", 981'522'556);
	GroupB.addStudent("Joanna", 23, "Female", 456'123'544);
	GroupC = GroupB;
	try
	{
		cout << "Name of the second student in group B is: " << GroupC.getStudent(1).getName() << ".\n";
	}
	catch (const invalidIndex& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}

	cout << endl;

	char temp[] = "Words";
	mString str1(temp);
	mString str2;
	str2 = str1;
	cout << str2.get() << endl;

	cout << endl;

	Date d1(1, 10, 1999);
	Date d2(31, 10, 2004);
	Date d3(13, 8, 2000);
	Date d4(15, 8, 2000);
	Date d5, d6, d7, d8;
	Date w1, w2, w3, w4;

	w1 = d1 - 30;
	w1.getDate();

	int diffDate = d2 - d1;

	d3 += 15;
	d3.getDate();

	if (d4 >= d3)
		cout << "Date 4 is later then date 3.\n";
}