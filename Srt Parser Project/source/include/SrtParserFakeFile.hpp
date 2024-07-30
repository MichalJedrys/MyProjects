#ifndef SRTPARSERFAKEFILE_HPP
#define SRTPARSERFAKEFILE_HPP

#include "SrtBase.hpp"

class SrtParserFakeFile : public SrtParserBase
{
public:
	void ReadFile(std::istream& input) override;

	std::string WriteToFile(std::string filename) override;
};

#endif // SRTPARSERFAKEFILE_HPP