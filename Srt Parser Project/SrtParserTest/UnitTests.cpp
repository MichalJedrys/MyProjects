#include "pch.h"
#include "../SrtParser/SrtParserFakeFile.h"

//Function for performance check
string fillA(int i)
{
	string out;
	for (int j = 0; j <= i%10; j++)
	{
		out = out + "A";
	}
	return out;
}

TEST(SrtParserTests, ExapmleFile) {

	const string TestedInput = "1\n00:00 : 01, 000 -- > 00:00 : 05, 500\nRaz\ndva\ntri\n\n2\n00:00 : 06, 000 -- > 00:00 : 09, 500\nchetyre piat\n\n3\n00:00 : 10, 000 -- > 00:00 : 15, 500\nvyshel\nzaichiq\npoguliat\n\n4\n00:00 : 11, 000 -- > 00:00 : 19, 500\nbelyi zaichiq\n\n5\n00 : 00 : 12, 000 -- > 00:00 : 14, 500\nnaglyi zaichiq\n\n6\n00 : 00 : 13, 000 -- > 00:00 : 16, 500\nvyshel\ni ushel\n\n7\n00 : 00 : 15, 000 -- > 00:00 : 17, 500\ntoptun\n\n8\n00 : 00 : 19, 500 -- > 00:00 : 19, 600\nvot i vsyo\n\n";
	const string TestedOutput = "at 1,00 show 'Raz\ndva\ntri'\nat 5,50 show ''\nat 6,00 show 'chetyre piat'\nat 9,50 show ''\nat 10,00 show 'vyshel\nzaichiq\npoguliat'\nat 11,00 show 'vyshel\nzaichiq\npoguliat\nbelyi zaichiq'\nat 12,00 show 'vyshel\nzaichiq\npoguliat\nbelyi zaichiq\nnaglyi zaichiq'\nat 13,00 show 'vyshel\nzaichiq\npoguliat\nbelyi zaichiq\nnaglyi zaichiq\nvyshel\ni ushel'\nat 14,50 show 'vyshel\nzaichiq\npoguliat\nbelyi zaichiq\nvyshel\ni ushel'\nat 15,00 show 'vyshel\nzaichiq\npoguliat\nbelyi zaichiq\nvyshel\ni ushel\ntoptun'\nat 15,50 show 'belyi zaichiq\nvyshel\ni ushel\ntoptun'\nat 16,50 show 'belyi zaichiq\ntoptun'\nat 17,50 show 'belyi zaichiq'\nat 19,50 show 'vot i vsyo'\nat 19,60 show ''\n";
	string Output;

	istringstream istr(TestedInput);

	SrtParserFakeFile SP_fake;

	SP_fake.ReadFile(istr);

	SP_fake.Arrange();

	Output = SP_fake.WriteToFile(Output);

	EXPECT_EQ(Output,TestedOutput);
}

TEST(SrtParserTests, SimpleCase)
{
	const string TestedInput = "1\n00:00 : 01, 000 -- > 00:00 : 05, 500\nRaz\ndva\ntri\n\n2\n00:00 : 06, 000 -- > 00:00 : 09, 500\nchetyre piat\n\n3\n00:00 : 10, 000 -- > 00:00 : 12, 500\nvyshel\nzaichiq\npoguliat\n\n";
	const string TestedOutput = "at 1,00 show 'Raz\ndva\ntri'\nat 5,50 show ''\nat 6,00 show 'chetyre piat'\nat 9,50 show ''\nat 10,00 show 'vyshel\nzaichiq\npoguliat'\nat 12,50 show ''\n";
	string Output;

	istringstream istr(TestedInput);

	SrtParserFakeFile SP_fake;

	SP_fake.ReadFile(istr);

	SP_fake.Arrange();

	Output = SP_fake.WriteToFile(Output);

	EXPECT_EQ(Output, TestedOutput);
}


TEST(SrtParserTests, DoubleNewLineEnd)
{
	const string TestedInput = "1\n00:00 : 01, 000 -- > 00:00 : 05, 500\nRaz\ndva\ntri\n\n2\n00:00 : 06, 000 -- > 00:00 : 09, 500\nchetyre piat\n\n3\n00:00 : 10, 000 -- > 00:00 : 12, 500\nvyshel\nzaichiq\npoguliat";
	const string TestedOutput = "at 1,00 show 'Raz\ndva\ntri'\nat 5,50 show ''\nat 6,00 show 'chetyre piat'\nat 9,50 show ''\n";
	string Output;

	istringstream istr(TestedInput);

	SrtParserFakeFile SP_fake;

	SP_fake.ReadFile(istr);

	SP_fake.Arrange();

	Output = SP_fake.WriteToFile(Output);

	EXPECT_EQ(Output, TestedOutput);
}


TEST(SrtParserTests, IncorrectRecordNumbers)
{
	const string TestedInput = "1\n00:00 : 01, 000 -- > 00:00 : 05, 500\nRaz\ndva\ntri\n\n2dD\n00:00 : 06, 000 -- > 00:00 : 09, 500\nchetyre piat\n\n2\n00:00 : 10, 000 -- > 00:00 : 12, 500\nvyshel\nzaichiq\npoguliat\n\n";
	const string TestedOutput = "at 1,00 show 'Raz\ndva\ntri'\nat 5,50 show ''\nat 10,00 show 'vyshel\nzaichiq\npoguliat'\nat 12,50 show ''\n";
	string Output;

	istringstream istr(TestedInput);

	SrtParserFakeFile SP_fake;

	SP_fake.ReadFile(istr);

	SP_fake.Arrange();

	Output = SP_fake.WriteToFile(Output);

	EXPECT_EQ(Output, TestedOutput);
}

TEST(SrtParserTests, Nesting)
{
	const string TestedInput = "1\n00:00 : 02, 000 -- > 00:00 : 12, 000\nA\nA\nA\n\n2\n00:00 : 04, 000 -- > 00:00 : 10, 000\nB\nB\nB\n\n3\n00:00 : 06, 000 -- > 00:00 : 08, 000\nC\nC\nC\n\n";
	const string TestedOutput = "at 2,00 show 'A\nA\nA'\nat 4,00 show 'A\nA\nA\nB\nB\nB'\nat 6,00 show 'A\nA\nA\nB\nB\nB\nC\nC\nC'\nat 8,00 show 'A\nA\nA\nB\nB\nB'\nat 10,00 show 'A\nA\nA'\nat 12,00 show ''\n";
	string Output;

	istringstream istr(TestedInput);

	SrtParserFakeFile SP_fake;

	SP_fake.ReadFile(istr);

	SP_fake.Arrange();

	Output = SP_fake.WriteToFile(Output);

	EXPECT_EQ(Output, TestedOutput);
}

TEST(SrtParserTests, Empty)
{
	const string TestedInput = "";
	const string TestedOutput = "";
	string Output;

	istringstream istr(TestedInput);

	SrtParserFakeFile SP_fake;

	SP_fake.ReadFile(istr);

	SP_fake.Arrange();

	Output = SP_fake.WriteToFile(Output);

	EXPECT_EQ(Output, TestedOutput);
}

TEST(SrtParserTests, Intersection)
{
	const string TestedInput = "1\n00:00 : 02, 000 -- > 00:00 : 08, 000\nA\nA\nA\n\n2\n00:00 : 04, 000 -- > 00:00 : 10, 000\nB\nB\nB\n\n3\n00:00 : 06, 000 -- > 00:00 : 12, 000\nC\nC\nC\n\n";
	const string TestedOutput = "at 2,00 show 'A\nA\nA'\nat 4,00 show 'A\nA\nA\nB\nB\nB'\nat 6,00 show 'A\nA\nA\nB\nB\nB\nC\nC\nC'\nat 8,00 show 'B\nB\nB\nC\nC\nC'\nat 10,00 show 'C\nC\nC'\nat 12,00 show ''\n";
	string Output;

	istringstream istr(TestedInput);

	SrtParserFakeFile SP_fake;

	SP_fake.ReadFile(istr);

	SP_fake.Arrange();

	Output = SP_fake.WriteToFile(Output);

	EXPECT_EQ(Output, TestedOutput);
}

TEST(SrtParserTests, Performance)
{
	int N = 5000;
	string TestedInput;
	string strA;
	for (int i = 0; i < N; i++)
	{
		strA = fillA(i);
		TestedInput = TestedInput + to_string(i) + "\n00:00 : 01,000 -- > 00:00 : 10,000\nThe code is " + strA + "!\n\n";
	}

	string TestedOutput = "at 1,00 show '";
	for (int i = 1; i < 10; i++)
	{
		strA = fillA(i);
		TestedOutput = TestedOutput + "The code is " + strA + "!\n";
	}
	TestedOutput.pop_back();
	TestedOutput = TestedOutput + "'\nat 10,00 show ''\n";

	string Output;

	istringstream istr(TestedInput);

	SrtParserFakeFile SP_fake;

	SP_fake.ReadFile(istr);

	SP_fake.Arrange();

	Output = SP_fake.WriteToFile(Output);

	EXPECT_EQ(Output, TestedOutput);
}

TEST(SrtParserTests, WrongTimes)
{
	const string TestedInput = "1\n00:00 : 01, 000 -- > 00:00 : 05, 500\nRaz\ndva\ntri\n\n2\n00:AA : 06, 000 -- > 00:00 : 09, 500\nchetyre piat\n\n3\n00:00 : 10, 000 -- > 00:00 : 999, 500\nvyshel\nzaichiq\npoguliat\n\n3\n00:00 : 12, 00DD0 -> 00:00 : 15, 500\nvyshel\nzaichiq\npoguliat\n\n";
	const string TestedOutput = "at 1,00 show 'Raz\ndva\ntri'\nat 5,50 show ''\n";
	string Output;

	istringstream istr(TestedInput);

	SrtParserFakeFile SP_fake;

	SP_fake.ReadFile(istr);

	SP_fake.Arrange();

	Output = SP_fake.WriteToFile(Output);

	EXPECT_EQ(Output, TestedOutput);
}