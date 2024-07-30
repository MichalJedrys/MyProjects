#ifndef SRTPARSERREALFILE_HPP
#define SRTPARSERREALFILE_HPP

#include "SrtBase.hpp"

class SrtParserRealFile : public SrtParserBase
{
public:
	void ReadFile(std::istream& input) override;

	std::string WriteToFile(std::string filename) override;
};

#endif // SRTPARSERREALFILE_HPP