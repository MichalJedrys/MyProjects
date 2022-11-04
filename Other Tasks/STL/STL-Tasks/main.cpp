#include <iostream>
#include "string_analyzer.h"
#include "real_file.h"


int main()
{
	string_analyzer r_file(new real_file());

	string Output;
	r_file.config_f(Output, "Config_Output.txt");

	for (auto k : Output) {
		std::cout << k;
	}
	std::cout << "\n";
}