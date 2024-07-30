#include "SrtParserRealFile.hpp"

using namespace std;

int main()
{
	try
	{
		SrtParserRealFile SP;

		//Import data form file
		ifstream InputFile;
		InputFile.open("TestInput.srt");

		//Read file
		SP.ReadFile(InputFile);

		InputFile.close();

		//Change format of data
		SP.Arrange();

		//Save to output file
		SP.WriteToFile("Output.txt");
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		system("pause");
	}
	return 0;
}