#pragma once
#include <string>
#include "string_provider.h"
#include "AbsoluteMax.h"
#include "ConfigurationTask.h"
#include "NumberOfDiffNums.h"
#include "RemoveDuplicates.h"

class string_analyzer
{
private:
	string_provider *_string_provider;
public:
	string_analyzer(string_provider *stringprovider)
	{
		_string_provider = stringprovider;
	}
	~string_analyzer()
	{
		delete _string_provider;
	}

	void config_f(std::string& output, std::string outputfile)
	{
		auto lines = _string_provider->get_lines();
		ConfigTask(lines, output);
		ofstream configOut;
		configOut.open(outputfile);
		for (auto k : output) {
			configOut << k;
		}
		configOut.close();
	}

	void config_f(std::string& output)
	{
		auto lines = _string_provider->get_lines();
		ConfigTask(lines, output);
	}

	int abs_f()
	{
		auto lines = _string_provider->get_lines();
		return AbsMax(lines);
	}

	void rmv_f(vector<int> &RevNums)
	{
		auto lines = _string_provider->get_lines();
		RmvNums(lines, RevNums);
	}

	int diff_f()
	{
		auto lines = _string_provider->get_lines();
		return NumOfDiffNums(lines);
	}


};