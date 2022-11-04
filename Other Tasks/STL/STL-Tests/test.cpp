#include "pch.h"
#include "../STL-Tasks/string_analyzer.h"
#include "fake_file_abs.h"
#include "fake_file_diff.h"
#include "fake_file_rmv.h"
#include "fake_file_config.h"



//ABSOLUTE VALUE
TEST(AbsTest, SimpleTest) {

	string_analyzer AbsSimpleT(new AbsSimple());
	EXPECT_EQ(AbsSimpleT.abs_f(),9);
}

TEST(AbsTest, NegativeTest) {

	string_analyzer AbsNegativeT(new AbsNegative());
	EXPECT_EQ(AbsNegativeT.abs_f(),10);
}

TEST(AbsTest, MixedTest) {

	string_analyzer AbsMixedT(new AbsMixed());
	EXPECT_EQ(AbsMixedT.abs_f(),2111);
}

TEST(AbsTest, LongInputTest) {

	string_analyzer AbsLongInputT(new AbsLongInput());
	EXPECT_EQ(AbsLongInputT.abs_f(), 65002);
}

TEST(AbsTest, EmptyTest) {

	string_analyzer AbsEmptyT(new AbsEmpty());
	EXPECT_EQ(AbsEmptyT.abs_f(), 0);
}

TEST(AbsTest, OneNumberTest) {

	string_analyzer AbsOneNumberT(new AbsOneNumber());
	EXPECT_EQ(AbsOneNumberT.abs_f(), 65);
}

TEST(AbsTest, EqualNumbersTest) {

	string_analyzer AbsEqualNumbersT(new AbsEqualNumbers());
	EXPECT_EQ(AbsEqualNumbersT.abs_f(), 1);
}


//NUMBER OF DIFFRENT VALUES
TEST(DiffTest, SimpleTest) {

	string_analyzer DiffSimpleT(new DiffSimple());
	EXPECT_EQ(DiffSimpleT.diff_f(), 5);
}

TEST(DiffTest, MixedTest) {

	string_analyzer DiffMixedT(new DiffMixed());
	EXPECT_EQ(DiffMixedT.diff_f(), 11);
}

TEST(DiffTest, LongInputTest) {

	string_analyzer DiffLongInputT(new DiffLongInput());
	EXPECT_EQ(DiffLongInputT.diff_f(), 130000);
}


TEST(DiffTest, OneNumberTest) {

	string_analyzer DiffOneNumberT(new DiffOneNumber());
	EXPECT_EQ(DiffOneNumberT.diff_f(), 1);
}

TEST(DiffTest, EqualNumbersTest) {

	string_analyzer DiffEqualNumbersT(new DiffEqualNumbers());
	EXPECT_EQ(DiffEqualNumbersT.diff_f(), 1);
}


//REMOVE DUPLICATES
TEST(RemoveTest, SimpleTest) {

	string_analyzer RmvSimpleT(new RmvSimple());
	vector<int>Nums{};
	vector<int>Check{0,1,2,3,4,5,6,7,8,9};
	RmvSimpleT.rmv_f(Nums);
	EXPECT_EQ(Nums, Check);
}

TEST(RemoveTest, MixedTest) {

	string_analyzer RmvMixedT(new RmvMixed());
	vector<int>Nums{};
	vector<int>Check{ -700,-200,-9,-1,0,5,6,11,21,33,4243 };
	RmvMixedT.rmv_f(Nums);
	EXPECT_EQ(Nums, Check);
}

TEST(RemoveTest, LongInputTest) {

	string_analyzer RmvLongInputT(new RmvLongInput());
	vector<int>Nums{};
	vector<int>Check;
	int N = 65000;
	for (int i = 0; i < N; i++) {
		Check.push_back(i);
	}
	RmvLongInputT.rmv_f(Nums);
	EXPECT_EQ(Nums, Check);
}

TEST(RemoveTest, EmptyTest) {

	string_analyzer RmvEmptyT(new RmvEmpty());
	vector<int>Nums{};
	vector<int>Check{};
	RmvEmptyT.rmv_f(Nums);
	EXPECT_EQ(Nums, Check);
}

TEST(RemoveTest, OneNumberTest) {

	string_analyzer RmvOneNumberT(new RmvOneNumber());
	vector<int>Nums{};
	vector<int>Check{ 700 };
	RmvOneNumberT.rmv_f(Nums);
	EXPECT_EQ(Nums, Check);
}


//CONFIGURATION TASK
TEST(ConfigTest, SimpleTest) {

	string_analyzer CfgSimpleT(new CfgSimple());
	string output="";
	string check = "Configuration\nMike - 33\nTom - 25\nJessica - 29\n\nMistakes\n";
	CfgSimpleT.config_f(output);
	EXPECT_EQ(output, check);
}

TEST(ConfigTest, FullTest) {

	string_analyzer CfgFullT(new CfgFull());
	string output = "";
	string check = "Configuration\nMike - 33\nTom - 25\nJessica - 29\nHours - 140\nspaces - '     '\nPlace - Cracow\n\nMistakes\n<string with invalid syntax 2>\n<string with invalid syntax 6>\n";
	CfgFullT.config_f(output);
	EXPECT_EQ(output, check);
}

TEST(ConfigTest, SpacesTest) {

	string_analyzer CfgSpacesT(new CfgSpaces());
	string output = "";
	string check = "Configuration\ntwospaces - '  '\nfivespaces - '     '\nninespaces - '         '\n\nMistakes\n";
	CfgSpacesT.config_f(output);
	EXPECT_EQ(output, check);
}

TEST(ConfigTest, MistakesTest) {

	string_analyzer CfgMistakesT(new CfgMistakes());
	string output = "";
	string check = "Configuration\n\nMistakes\n<string with invalid syntax 1>\n<string with invalid syntax 2>\n<string with invalid syntax 3>\n";
	CfgMistakesT.config_f(output);
	EXPECT_EQ(output, check);
}

TEST(ConfigTest, EmptyTest) {

	string_analyzer CfgEmptyT(new CfgEmpty());
	string output = "";
	string check = "Configuration\n\nMistakes\n";
	CfgEmptyT.config_f(output);
	EXPECT_EQ(output, check);
}