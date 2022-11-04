#pragma once
#include <iostream>
#include <math.h>
#include <string>


using namespace std;

class Date
{
private:
	int day = 0;
	int month = 0;
	//string month;
	int year = 0;
public:
	Date()
	{
		int day = 0;
		int month = 0;
		//string month = "";
		int year = 0;
	}

	Date(int _day, int _month, int _year)
	{
		day = _day;
		month = _month;
		year = _year;
	}

	Date(const Date& d)
	{
		day = d.day;
		month = d.month;
		year = d.year;
	}

	~Date() {}

	void getDate()
	{
		cout << "Date is: " << day << "." << month << "." << year << endl;
	}

	void setDate(int _day, int _month, int _year)
	{
		day = _day;
		month = _month;
		year = _year;
	}

	Date& operator++()
	{
		day = day + 1;
		if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
		{
			month = month + 1;
			day = day - 31;
		}
		else if (month == 2 && day > 28)
		{
			month = month + 1;
			day = day - 28;
		}
		else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		{
			month = month + 1;
			day = day - 30;
		}
		if (month > 12)
		{
			month = 1;
			year = year + 1;
		}
		return *this;
	}

	Date& operator--()
	{
		day = day - 1;
		if ((month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11 || month == 1) && day == 0)
		{
			month = month - 1;
			day = 31;
		}
		else if (month == 3 && day == 0)
		{
			month = month - 1;
			day = 28;
		}
		else if ((month == 5 || month == 7 || month == 10 || month == 12) && day == 0)
		{
			month = month - 1;
			day = 30;
		}
		if (month == 0)
		{
			month = 12;
			year = year - 1;
		}
		return *this;
	}

	Date operator+(int numOfDays)
	{
		Date d;
		d.day = this->day;
		d.month = this->month;
		d.year = this->year;
		for (int i = 0; i < numOfDays; i++)
		{
			++d;
		}
		return d;
	}

	Date operator-(int numOfDays)
	{
		Date d;
		d.day = this->day;
		d.month = this->month;
		d.year = this->year;
		for (int i = 0; i < numOfDays; i++)
		{
			--d;
		}
		return d;
	}

	int operator-(const Date& d)
	{
		return abs((year - d.year) * 365 + (month - d.month) * 30 + (day - d.day));
	}

	Date& operator+=(int numOfDays)
	{
		for (int i = 0; i < numOfDays; i++)
		{
			++*this;
		}
		return *this;
	}

	Date& operator-=(int numOfDays)
	{
		for (int i = 0; i < numOfDays; i++)
		{
			--* this;
		}
		return *this;
	}

	bool operator<(const Date& d)
	{
		if (year < d.year)
			return true;
		if (month < d.month)
			return true;
		return (day < d.day);
	}

	bool operator>(const Date& d)
	{
		if (year > d.year)
			return true;
		if (month > d.month)
			return true;
		return (day > d.day);
	}

	bool operator<=(const Date& d)
	{
		if (year < d.year)
			return true;
		if (month < d.month)
			return true;
		return (day <= d.day);
	}

	bool operator>=(const Date& d)
	{
		if (year > d.year)
			return true;
		if (month > d.month)
			return true;
		return (day >= d.day);
	}

	bool operator==(const Date& d)
	{
		return ((year == d.year) && (month == d.month) && (day == d.day));
	}
	bool operator!=(const Date& d)
	{
		return ((year != d.year) || (month != d.month) || (day != d.day));
	}

	friend istream& operator>>(istream& s, Date& d);
	friend ostream& operator<<(ostream& o, const Date& d);
};
