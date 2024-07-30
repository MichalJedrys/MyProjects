#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>

class IncorrectOption : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Input value is incorrect!";
	}
};

class InvalidOperator : public std::exception
{
public:
	const char* what() const noexcept override 
	{
		return "Invalid Operator!";
	}
};

class IncorrectMTOption : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Input value is incorrect!";
	}
};

class InvalidPayment : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Machine does not accept this currency!";
	}
};

#endif // EXCEPTIONS_HPP