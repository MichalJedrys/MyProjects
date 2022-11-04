#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "../STL-Tasks/string_provider.h"

class AbsSimple : public string_provider
{
private:
	string numbers = "0 1 2 3 4 5 6 7 8 9";

public:
	string get_lines() override
	{
		return numbers;
	}
};

class AbsNegative: public string_provider
{
private:
	string numbers = "-1 -2 -3 -4 -5 -6 -7 -8 -9 -10";

public:
	string get_lines() override
	{
		return numbers;
	}
};

class AbsMixed : public string_provider
{
private:
	string numbers = "-13 123 -22 -313 0 -23 445 123 -1236 -755 821 0 -1022 312 -2111 ";

public:
	string get_lines() override
	{
		return numbers;
	}
};

class AbsLongInput : public string_provider
{
private:
	string numbers;

public:
	string get_lines() override
	{
		int N = 65001;
		for (int i = -65002; i < N; i++) {
			numbers = numbers + ' ' + to_string(i);
		}
		return numbers;
	}
};

class AbsEmpty : public string_provider
{
private:
	string numbers = "";

public:
	string get_lines() override
	{
		return numbers;
	}
};

class AbsOneNumber : public string_provider
{
private:
	string numbers = "65";

public:
	string get_lines() override
	{
		return numbers;
	}
};

class AbsEqualNumbers : public string_provider
{
private:
	string numbers = "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1";

public:
	string get_lines() override
	{
		return numbers;
	}
};