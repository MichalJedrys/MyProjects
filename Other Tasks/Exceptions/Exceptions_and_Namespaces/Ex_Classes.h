#include <exception>

using namespace std;

class outOfRange : public exception
{
public:
	const char* what() const override
	{
		return "Value is out of range!";
	}
};

class noFile : public exception
{
public:
	const char* what() const override
	{
		return "File not found!";
	}
};

class devideByZero : public exception
{
public:
	const char* what() const override
	{
		return "Invalid value";
	}
};

class intOverflow : public exception
{
public:
	const char* what() const override
	{
		return "Result value is overflowed.";
	}
};

class invalidIndex : public exception
{
public:
	const char* what() const override
	{
		return "Element with that index cannot be reached.";
	}
};

class notEvenNumber : public exception
{
public:
	const char* what() const override
	{
		return "Invalid value. Size of array must be an even number.";
	}
};

