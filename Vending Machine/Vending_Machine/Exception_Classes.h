#pragma once
#include <exception>

using namespace std;

class IncorrectOption : public exception
{
public:
	const char* what() const override
	{
		return "Input value is incorrect!";
	}
};

class InvalidOperator : public exception
{
public:
	const char* what() const override
	{
		return "Invalid Operator!";
	}
};

class IncorrectMTOption : public exception
{
public:
	const char* what() const override
	{
		return "Input value is incorrect!";
	}
};

class InvalidPayment : public exception
{
public:
	const char* what() const override
	{
		return "Machine does not accept this currency!";
	}
};