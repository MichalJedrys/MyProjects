#include "namespaces.h"
#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class st_gr::st::student
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

	~student(){}

	void setName(string _name)
	{
		name = _name;
	}

	string getName()
	{
		return name;
	}

	void setAge(int _age)
	{
		if (_age >= 0 && _age < 99)
			age = _age;
	}

	int getAge()
	{
		return age;
	}

	void setGender(string _gender)
	{
		if (_gender == "Male" || _gender == "Female")
			gender = _gender;
	}

	string getGender()
	{
		return gender;
	}

	void setPhoneNr(int _phone_nr)
	{
		if (_phone_nr > 100000000 && _phone_nr < 1000000000)
			phone_number = _phone_nr;
	}

	int getPhoneNr()
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
};

class st_gr::groupOfStudents
{
private:
	vector<st_gr::st::student>list;
public:
	groupOfStudents(){}

	~groupOfStudents() {}

	void addStudent(string _name, int _age, string _gender, int _phone_nr)
	{
		st_gr::st::student newStudent;
		newStudent.setName(_name);
		newStudent.setAge(_age);
		newStudent.setGender(_gender);
		newStudent.setPhoneNr(_phone_nr);

		list.push_back(newStudent);
	}

	st_gr::st::student getStudent(int index)
	{
		return list[index];
	}

	//We can add more arguments to choose student more accuratly in case of for example two student which the same name. 
	//This is a case where we assume that each student has a different name.
	void removeStudent(string _name)
	{
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i].getName() == _name) {
				list.erase(list.begin() + i);
			}
		}
	}

	//This is the same principal as in previous example
	void printInfo(string _name)
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

	//This is the same principal as in previous example
	//Option: 1-name, 2-age, 3-gender, 4-phone number
	void changeData(string _name, int option)
	{
		for (int i = 0; i < list.size(); i++)
		{

			if (list[i].getName() == _name) {
				string t_name;
				int t_age;
				string t_gender;
				int t_phone_nr;
				switch (option)
				{
				case 1:
					cout << "Enter new name: ";
					cin >> t_name;
					list[i].setName(t_name);
					break;
				case 2:
					cout << "Enter new age: ";
					cin >> t_age;
					list[i].setAge(t_age);
					break;
				case 3:
					cout << "Enter new gender: ";
					cin >> t_gender;
					list[i].setGender(t_gender);
					break;
				case 4:
					cout << "Enter new phone number: ";
					cin >> t_phone_nr;
					list[i].setPhoneNr(t_phone_nr);
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
};

class shp::shape
{
protected:
	static double ar;
	static int count;
	static double side;
	static double height;
public:
	static int countCalc()
	{
		return count;
	}
};

double shp::shape::ar;
int shp::shape::count;
double shp::shape::side;
double shp::shape::height;

class shp::square : public shp::shape
{
public:
	square(double _side)
	{
		side = _side;
	}
	static double area()
	{
		ar = side * side;
		count++;
		return ar;
	}
};

class shp::rectangle : public shp::shape
{
public:
	rectangle(double _side, double _heigth)
	{
		side = _side;
		height = _heigth;
	}
	static double area()
	{
		ar = side * height;
		count++;
		return ar;
	}
};

class shp::rhombus : public shp::shape
{
public:
	rhombus(double _side, double _heigth)
	{
		side = _side;
		height = _heigth;
	}
	static double area()
	{
		ar = side * height;
		count++;
		return ar;
	}
};

class shp::triangle : public shp::shape
{
private:
	static double side2;
	static double side3;
	static int type;
public:
	triangle(double _side, double _height)
	{
		side = _side;
		height = _height;
		type = 1;
	}

	triangle(double _side)
	{
		side = _side;
		type = 2;
	}

	triangle(double _side1, double _side2, double _side3)
	{
		side = _side1;
		side2 = _side2;
		side3 = _side3;
		type = 3;
	}

	static double area()
	{
		switch (type)
		{
		case 1:
			ar = (side * height) / 2;
			count++;
			return ar;
		case 2:
			ar = (side * side * sqrt(3.0)) / 4;
			count++;
			return ar;
		case 3:
			static double p = (side + side2 + side3) / 2;
			ar = sqrt(p * (p - side) * (p - side2) * (p - side3));
			count++;
			return ar;
		default:
			return 0;
		}

	}
};

double shp::triangle::side2;
double shp::triangle::side3;
int shp::triangle::type;

class cnt::vectorC
{
private:
	int* arr = nullptr;
	int max_size;
	int length;
public:
	vectorC()
	{
		arr = new int[1];
		max_size = 1;
		length = 0;
	}

	~vectorC()
	{
		delete[] arr;
	}

	//Get size of vector
	int size()
	{
		return length;
	}

	//Add new element to the back
	void push(int n)
	{
		if (length == max_size) {
			int* arr_t = new int[2 * max_size];

			for (int i = 0; i < length; i++) {
				arr_t[i] = arr[i];
			}
			delete[] arr;
			max_size *= 2;
			arr = arr_t;
		}
		arr[length] = n;
		length++;
	}

	//Add new element at index
	void push(int n, int index)
	{
		if (index == max_size) {
			push(n);
		}
		else {
			arr[index] = n;
		}
	}

	//Remove element from the back
	void pop()
	{
		length--;
	}


	//Get value by index
	int get(int index)
	{
		if (index < length)
		{
			return arr[index];
		}
	}

	//Get first element
	int front()
	{
		if (length > 1) {
			return arr[0];
		}
	}

	//Get last element
	int back() {
		if (length > 0) {
			return arr[length];
		}
	}

	//Get capacity of vector
	int capacity() {
		return max_size;
	}

	//Clear vector
	void clear() {
		length = 0;
	}
};