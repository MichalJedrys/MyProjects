#pragma once
#include <string>
#include <iostream>

using namespace std;

class student
{
private:
	string name;
	int age = 0;
	string gender = "";
	int phone_number = 0;
public:
	student(){}

	student(const student& s)
	{
		this->name = s.name;
		this->age = s.age;
		this->gender = s.gender;
		this->phone_number = s.phone_number;
	}

	student(student&& s) noexcept
	{
		this->name = s.name;
		this->age = s.age;
		this->gender = s.gender;
		this->phone_number = s.phone_number;
	}

	~student(){}

	void setName(string _name)
	{
		name = _name;
	}

	string getName() const
	{
		return name;
	}

	void setAge(int _age)
	{
		if (_age >= 0 && _age < 99)
			age = _age;
	}

	int getAge() const
	{
		return age;
	}

	void setGender(string _gender)
	{
		if (_gender == "Male" || _gender == "Female")
			gender = _gender;
	}

	string getGender() const
	{
		return gender;
	}

	void setPhoneNr(int _phone_nr)
	{
		if (_phone_nr > 100000000 && _phone_nr < 1000000000)
			phone_number = _phone_nr;
	}

	int getPhoneNr() const
	{
		return phone_number;
	}

	void showInfo()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Gender: " << gender << endl;
		cout << "Phone number: " << phone_number << endl;
	}

	student& operator=(const student& s)
	{
		if (this == &s)
			return *this;
		this->name = s.name;
		this->age = s.age;
		this->gender = s.gender;
		this->phone_number = s.phone_number;

		return *this;
	}

	friend istream& operator>>(istream& is, student& s);
	friend ostream& operator<<(ostream& o,const student& s);
};