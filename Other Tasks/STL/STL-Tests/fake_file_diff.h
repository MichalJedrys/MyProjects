#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "../STL-Tasks/string_provider.h"

class DiffSimple : public string_provider
{
private:
	string numbers = "15 1 2 2 3 3 3 4 4 4 4 5 5 5 5 5";

public:
	string get_lines() override
	{
		return numbers;
	}
};

class DiffMixed : public string_provider
{
private:
	string numbers = "17 -10 4 -21 0 17 6 -10 15 3 0 22 -21 4 5 6 6 78";

public:
	string get_lines() override 
	{
		return numbers;
	}
};

class DiffLongInput : public string_provider
{
private:
	string numbers;

public:
	string get_lines() override
	{
		int N = 65001;
		for (int i = -65000; i < N; i++) {
			numbers = numbers + ' ' + to_string(i);
		}
		return numbers;
	}
};

class DiffOneNumber : public string_provider
{
private:
	string numbers = "1 7";

public:
	string get_lines() override
	{
		return numbers;
	}
};

class DiffEqualNumbers : public string_provider
{
private:
	string numbers = "5 1 1 1 1 1";

public:
	string get_lines() override
	{
		return numbers;
	}
};