#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "../STL-Tasks/string_provider.h"

class RmvSimple : public string_provider
{
private:
	string numbers = "0 0 1 1 1 1 2 2 3 3 3 4 4 4 4 4 4 5 6 6 7 7 7 7 8 8 8 9 9";

public:
	string get_lines() override
	{
		return numbers;
	}
};

class RmvMixed : public string_provider
{
private:
	string numbers = "-9 0 4243 6 21 11 5 -200 0 -700 33 -200 21 0 -1 5 -9 6";

public:
	string get_lines() override
	{
		return numbers;
	}
};

class RmvLongInput : public string_provider
{
private:
	string numbers;

public:
	string get_lines() override
	{
		int N = 65000;
		for (int i = 0; i < N; i++) {
			numbers = numbers + ' ' + to_string(i);
		}
		return numbers;
	}
};

class RmvEmpty : public string_provider
{
private:
	string numbers = "";

public:
	string get_lines() override
	{
		return numbers;
	}
};

class RmvOneNumber : public string_provider
{
private:
	string numbers = "700";

public:
	string get_lines() override
	{
		return numbers;
	}
};