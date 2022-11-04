#pragma once
#include <string>

class string_provider
{
public:
	virtual std::string get_lines() = 0;
	virtual ~string_provider() = default;
};