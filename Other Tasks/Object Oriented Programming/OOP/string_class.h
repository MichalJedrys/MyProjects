#pragma once
#include <string>

using namespace std;

class mString
{
private:
	char* str;

public:
	mString() : str{ nullptr } {}

	mString(char* c)
	{
		if (c == nullptr)
		{
			str = nullptr;
		}
		else
		{
			str = new char[sizeof(c)];
			strcpy_s(str, sizeof(c), c);
		}
	}

	mString(const mString& s) : mString(s.str) {}

	//MOVE CONSTRUCTOR
	mString(mString&& s) noexcept
	{
		str = s.str;
		s.str = nullptr;
	}

	~mString()
	{
		if (str != nullptr)
			delete str;
	}

	char* get() const
	{
		return str;
	}

	//OPERATOR OVERLOADING
	mString& operator=(const mString& c)
	{
		if (this == &c)
			return *this;
		if (!sizeof(str))
		{
			delete[] str;
		}
		str = new char[sizeof(c)];
		strcpy_s(str, sizeof(c.str), c.str);
		return *this;
	}

	friend istream& operator>>(istream& is, mString& v);
	friend ostream& operator<<(ostream& o, const mString& v);
};