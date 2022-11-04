#pragma once
#include "SrtBase.h"

using namespace std;

class SrtParserRealFile : public SrtParserBase
{
public:
	void ReadFile(istream &input) override
	{
		std::string data_in(std::istreambuf_iterator<char>(input), {});
		data = data_in;
	}

	string WriteToFile(string filename) override
	{
		ofstream OutputFile;
		OutputFile.open(filename, ios::out | ios::trunc);
		OutputFile.imbue(locale("fr_FR"));

		for (auto &p : vec)
		{
			OutputFile << "at " << fixed << setprecision(2) << p.first << " show '" << p.second << "'\n";
		}
		OutputFile.close();

		return "";
	}
};

