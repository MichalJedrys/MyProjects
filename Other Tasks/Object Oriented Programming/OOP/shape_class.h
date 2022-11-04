#pragma once
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class shape
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

double shape::ar;
int shape::count;
double shape::side;
double shape::height;


class square : public shape
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

class rectangle : public shape
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

class rhombus : public shape
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

class triangle : public shape
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

double triangle::side2;
double triangle::side3;
int triangle::type;

