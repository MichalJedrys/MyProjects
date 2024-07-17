#include "SrtParserRealFile.h"

using namespace std;

int main()
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

	return 0;
}