#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "../STL-Tasks/string_provider.h"

class CfgSimple : public string_provider
{
private:
	std::string input = "Mike 33 #HR\nTom 25 #IT\nJessica 29 #Sales";

public:
	std::string get_lines() override
	{
		return input;
	}
};

class CfgFull : public string_provider
{
private:
	std::string input = "Mike 33 #HR\ndd dd dd\nTom 25 #IT\nJessica     29 #Sales\nHours    140\nqweqwe11e\nspaces     \nPlace Cracow ";

public:
	std::string get_lines() override
	{
		return input;
	}
};

class CfgSpaces : public string_provider
{
private:
	std::string input = "twospaces  \nfivespaces     \nninespaces         \n";

public:
	std::string get_lines() override
	{
		return input;
	}
};

class CfgMistakes : public string_provider
{
private:
	std::string input = "oneword\nthree (3) words\nthis is more then two words\n";

public:
	std::string get_lines() override
	{
		return input;
	}
};

class CfgEmpty : public string_provider
{
private:
	std::string input =  "";

public:
	std::string get_lines() override
	{
		return input;
	}
};