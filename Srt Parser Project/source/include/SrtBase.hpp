#ifndef SRTBASE_HPP
#define SRTBASE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <istream>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <sstream>
#include <array>
#define pairVec std::vector<std::pair<double, std::string>>

bool TimeLineCheck(int i, char c);

class SrtParserBase
{
protected:
	std::string data;

	std::string output;

	pairVec vec;
public:
	virtual void ReadFile(std::istream& input) = 0;

	virtual pairVec Arrange();

	virtual std::string WriteToFile(std::string filename) = 0;
};

#endif // SRTBASE_HPP