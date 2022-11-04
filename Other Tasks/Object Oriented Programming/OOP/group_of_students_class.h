#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "student_class.h"
#include <exception>

using namespace std;

class invalidIndex: public exception
{
public:
	const char* what() const override
	{
		return "Invalid index value!";
	}
};

class groupOfStudents
{
private:
	vector<student>list;
public:
	groupOfStudents() {}

	groupOfStudents(const groupOfStudents& gos)
	{
		for (auto k : gos.list)
		{
			student newS(k);
			this->list.push_back(newS);

		}
	}

	groupOfStudents(groupOfStudents&& gos) noexcept
	{
		for (auto k : gos.list)
		{
			student newS(k);
			this->list.push_back(newS);
		}
	}

	~groupOfStudents() {}

	void addStudent(string _name, int _age, string _gender, int _phone_nr)
	{
		student newStudent;
		newStudent.setName(_name);
		newStudent.setAge(_age);
		newStudent.setGender(_gender);
		newStudent.setPhoneNr(_phone_nr);

		list.push_back(newStudent);
	}

	student getStudent(int index) const
	{
		if (index < 0 || index >= list.size())
		{
			throw invalidIndex();
		}
		return list[index];
	}

	void removeStudent(string _name)
	{
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i].getName() == _name) {
				list.erase(list.begin() + i);
			}
		}
	}

	void printInfo(string _name) const
	{
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i].getName() == _name) {
				cout << "Name: " << list[i].getName() << endl;
				cout << "Age: " << list[i].getAge() << endl;
				cout << "Gender: " << list[i].getGender() << endl;
				cout << "Phone number: " << list[i].getPhoneNr() << endl;
			}
		}
	}

	void changeData(string _name, int option)
	{
		for (int i = 0; i < list.size(); i++)
		{

			if (list[i].getName() == _name) {
				string name;
				int age;
				string gender;
				int phone_nr;
				switch (option)
				{
				case 1:
					cout << "Enter new name: ";
					cin >> name;
					list[i].setName(name);
					break;
				case 2:
					cout << "Enter new age: ";
					cin >> age;
					list[i].setAge(age);
					break;
				case 3:
					cout << "Enter new gender: ";
					cin >> gender;
					list[i].setGender(gender);
					break;
				case 4:
					cout << "Enter new phone number: ";
					cin >> phone_nr;
					list[i].setPhoneNr(phone_nr);
					break;
				default:
					cout << "Invalid value" << endl;
					break;
				}
			}
		}
	}

	void CheckDuplicateNames(string _name)
	{
		int n = 0;
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i].getName() == _name) {
				n++;
			}
		}
		cout << "There are " << n << " people named " << _name << "." << endl;
	}

	groupOfStudents& operator=(const groupOfStudents& gos)
	{
		if (this == &gos)
			return *this;

		for (auto k : gos.list)
		{
			student newS(k);
			this->list.push_back(newS);
		}

		return *this;
	}

	friend istream& operator>>(istream& is, groupOfStudents& gos);
	friend ostream& operator<<(ostream& o,const  groupOfStudents& gos);
};