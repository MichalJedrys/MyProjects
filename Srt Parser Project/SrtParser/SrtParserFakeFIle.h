#pragma once
#include "SrtBase.h"

using namespace std;

class SrtParserFakeFile : public SrtParserBase
{
public:
	void ReadFile(istream& input) override
	{
		std::string data_in(std::istreambuf_iterator<char>(input), {});
		data = data_in;
	}

	string WriteToFile(string filename) override
	{
		ostringstream toString;
		for (auto& p : vec)
		{
			toString << "at " << fixed << setprecision(2) << p.first << " show '" << p.second << "'\n";
		}
		filename = toString.str();

		for (auto &c : filename)
		{
			if (c == '.')
				c = ',';
		}

		return filename;
	}
};