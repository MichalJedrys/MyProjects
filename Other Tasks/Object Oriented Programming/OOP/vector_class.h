#pragma once
#include <string>

using namespace std;

class vectorC
{
private:
	int* arr;
	int max_size;
	int length;
public:
	vectorC()
	{
		arr =new int[1];
		max_size = 1;
		length = 0;
	}

	vectorC(const vectorC& vec)
	{
		arr = new int[vec.length];
		for (int i = 0; i < vec.length; i++)
		{
			arr[i] = vec.arr[i];
		}
		max_size = vec.max_size;
		length = vec.length;
	}

	vectorC(vectorC&& vec) noexcept
	{
		arr = new int[vec.length];
		for (int i = 0; i < vec.length; i++)
		{
			arr[i] = vec.arr[i];
		}
		max_size = vec.max_size;
		length = vec.length;
		vec.arr = nullptr;
	}

	~vectorC()
	{
		if (arr != nullptr)
			delete[] arr;
	}

	//Get size of vector
	int size() const
	{
		return length;
	}

	//Add new element to the back
	void push(int n)
	{
		if (length == max_size) {
			int* arr_t = new int[2 * max_size];

			for (int i = 0; i < length; i++) {
				arr_t[i] = arr[i];
			}
			delete[] arr;
			max_size *= 2;
			arr = arr_t;
		}
		arr[length] = n;
		length++;
	}

	//Add new element at index
	void push(int n, int index)
	{
		if (index == max_size) {
			push(n);
		}
		else {
			arr[index] = n;
		}
	}

	//Remove element from the back
	void pop()
	{
		length--;
	}


	//Get value by index
	int get(int index) const
	{
		if (index < length)
		{
			return arr[index];
		}
	}

	//Get first element
	int front() const
	{
		if (length > 1) {
			return arr[0];
		}
	}

	//Get last element
	int back() const
	{
		if (length > 0) {
			return arr[length];
		}
	}

	//Get capacity of vector
	int capacity() const
	{
		return max_size;
	}

	//Clear vector
	void clear()
	{
		length = 0;
	}

	vectorC& operator=(const vectorC& v)
	{
		if (this == &v)
			return *this;
		if (!length)
		{
			length = 0;
			delete[] arr;
		}
		length = v.length;
		if (!length){
			arr = nullptr;
		}else {
			arr = new int[length];
			for (int i = 0; i < length; i++)
				arr[i] = v.arr[i];
		}
		return *this;
	}

	vectorC& operator+(const vectorC& v)
	{
		if (length != v.length)
		{
			return *this;
		}
		for (int i = 0; i < length; i++)
		{
			arr[i] += v.arr[i];
		}
		return *this;

	}

	vectorC& operator-(const vectorC& v)
	{
		if (length != v.length)
		{
			return *this;
		}
		for (int i = 0; i < length; i++)
		{
			arr[i] -= v.arr[i];
		}
		return *this;
	}

	friend istream& operator>>(istream& is, vectorC& v);
	friend ostream& operator<<(ostream& o,const vectorC& v);
};