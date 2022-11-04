#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "../../Object Oriented Programming/OOP/date_storage_class.h"
#include "../../Object Oriented Programming/OOP/group_of_students_class.h"
#include "../../Object Oriented Programming/OOP/string_class.h"
#include "../../Object Oriented Programming/OOP/student_class.h"
#include "../../Object Oriented Programming/OOP/vector_class.h"
#include "../../Object Oriented Programming/OOP/shape_class.h"

istream& operator>>(istream& s, Date& d)
{
	cout << "Enter day: ";
	s >> d.day;
	cout << "Enter month: ";
	s >> d.month;
	cout << "Enter year : ";
	s >> d.year;
	return s;
}

ostream& operator<<(ostream& o,const Date& d)
{
	o << d.day << "." << d.month << "." << d.year;
	return o;
}

istream& operator>>(istream& is, student& s)
{
	cout << "Enter name: ";
	is >> s.name;
	cout << "Enter age: ";
	is >> s.age;
	cout << "Enter gender : ";
	is >> s.gender;
	cout << "Enter phone number: ";
	is >> s.phone_number;
	return is;
}

ostream& operator<<(ostream& o,const student& s)
{
	o << "\tName: " << s.name << "\n\tAge: " << s.age << "\n\tGender: " << s.gender << "\n\tPhone number: " << s.phone_number;
	return o;
}

istream& operator>>(istream& s, vectorC& v)
{	
	int i;
	s >> i;
	v.push(i);
	return s;
}

ostream& operator<<(ostream& o,const vectorC& v)
{
	for (int i = 0; i < v.length; i++)
	{
		o << v.arr[i] << " ";
	}
	return o;
}

istream& operator>>(istream& is, mString& s)
{
	string ins;
	is >> ins;
	s.str = new char[sizeof(ins)];
	strcpy_s(s.str,sizeof(ins),ins.c_str());
	return is;
}

ostream& operator<<(ostream& o,const mString& s)
{
	const char* s1 = s.str;
	string str(s1);
	o << str;
	return o;
}

istream& operator>>(istream& is, groupOfStudents& gos)
{
	student newS;
	is >> newS;
	gos.list.push_back(newS);
	return is;
}

ostream& operator<<(ostream& o,const groupOfStudents& gos)
{
	for (int i=0;i<gos.list.size();i++)
	{
		o << "Data of student nr. " << i + 1 << ".\n" << gos.list[i] << "\n";
	}
	return o;
}