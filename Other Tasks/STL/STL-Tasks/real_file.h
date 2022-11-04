#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "string_provider.h"



class real_file : public string_provider
{
public:
	std::string get_lines() override
	{
		std::string input = "";
		std::string filename("ConfigurationFile.txt");
		char c = 0;
		std::ifstream configIn(filename);
		if (!configIn.is_open()) {
			throw noFile();
		}
		while (configIn.get(c)) {
			input = input + c;
		}
		return input;
	}
};