#pragma once
#include <iostream>
#include <string>

template <typename T>
class Matrix
{
private:
	T* ptr;
	int row;
	int column;
	int size;
public:
	Matrix(int _row, int _column)
	{
		row = _row;
		column = _column;
		size = _row * _column;
		ptr = new T[size];
	}

	Matrix(const Matrix& m)
	{
		ptr = new T[m.size];
		for (int i = 0; i < m.size; i++)
		{
			ptr[i] = m.ptr[i];
		}
		row = m.row;
		column = m.column;
		size = m.size;
	}

	Matrix(Matrix&& m) noexcept
	{
		ptr = new T[m.size];
		for (int i = 0; i < m.size; i++)
		{
			ptr[i] = m.ptr[i];
		}
		row = m.row;
		column = m.column;
		size = m.size;
		m.ptr = nullptr;
	}

	~Matrix()
	{
		if (ptr != nullptr)
			delete[]ptr;
	}

	Matrix& operator=(const Matrix& m)
	{
		if (this == &m)
			return *this;
		if (!size)
		{
			size = 0;
			delete[] ptr;
		}
		size = m.size;
		row = m.row;
		column = m.column;
		if (!size) {
			ptr = nullptr;
		}
		else {
			ptr = new T[size];
			for (int i = 0; i < size; i++)
				ptr[i] = m.ptr[i];
		}
		return *this;
	}

	T operator()(int _i, int _j)
	{
		if (_i < row && _j < column)
		{
			return ptr[_i * column + _j];
		}
		else
		{
			return NULL;
		}
	}

	const T operator()(int _i, int _j) const
	{
		for (int k = 0; k < row; k++)
		{
			for (int l = 0; l < column; l++)
			{
				if (_i == k && _j == l)
					return ptr[k * column + l];
			}
		}
		return NULL;
	}

	void fill()
	{
		for (int k = 0; k < row; k++)
		{
			for (int l = 0; l < column; l++)
			{
				std::cin >> ptr[k * column + l];
			}
		}
		return;
	};

	void fill_random(T min, T max)
	{
		srand((unsigned)time(NULL));
		if (typeid(T) == typeid(int))
		{
			int range = max - min;
			for (int k = 0; k < row; k++)
			{
				for (int l = 0; l < column; l++)
				{
					ptr[k * column + l] = min + (rand() % range);
				}
			}
		}
		else
		{
			std::cout << "Only 'int' matrixes can be filled randomly!\n";
		}
	};

	const void display() const
	{
		for (int k = 0; k < row; k++)
		{
			for (int l = 0; l < column; l++)
			{
				std::cout << ptr[k * column + l] << " ";
			}
			std::cout << "\n";
		}
		return;
	};

	T max()
	{
		T max = ptr[0];
		for (int k = 0; k < row; k++)
		{
			for (int l = 0; l < column; l++)
			{
				if (max < ptr[k * column + l])
					max = ptr[k * column + l];
			}
		}
		return max;
	};

	T min()
	{
		T min = ptr[0];
		for (int k = 0; k < row; k++)
		{
			for (int l = 0; l < column; l++)
			{
				if (min > ptr[k * column + l])
					min = ptr[k * column + l];
			}
		}
		return min;
	};

	Matrix& operator+(const Matrix& m)
	{
		//Check if dimensions are correct
		if (row != m.row || column != m.column)
			return *this;
		for (int k = 0; k < row; k++)
		{
			for (int l = 0; l < column; l++)
			{
				this->ptr[k * column + l] = this->ptr[k * column + l] + m.ptr[k * column + l];
			}
		}
		return *this;
	};

	Matrix& operator+(T value)
	{
		for (int k = 0; k < row; k++)
		{
			for (int l = 0; l < column; l++)
			{
				this->ptr[k * column + l] = this->ptr[k * column + l] + value;
			}
		}
		return *this;
	}

	Matrix& operator-(const Matrix& m)
	{
		//Check if dimensions are correct
		if (row != m.row || column != m.column)
			return *this;
		for (int k = 0; k < row; k++)
		{
			for (int l = 0; l < column; l++)
			{
				this->ptr[k * column + l] = this->ptr[k * column + l] - m.ptr[k * column + l];
			}
		}
		return *this;
	};

	Matrix& operator-(T value)
	{
		for (int k = 0; k < row; k++)
		{
			for (int l = 0; l < column; l++)
			{
				this->ptr[k * column + l] = this->ptr[k * column + l] - value;
			}
		}
		return *this;
	}

	Matrix operator*(const Matrix& m)
	{
		T sum = 0;
		//Check if dimensions are correct
		if (column != m.row)
		{
			std::cout << "Invalid dimenstions!\n";
		}
		else {
			Matrix newM(row, m.column);
			for (int k = 0; k < row; k++)
			{
				for (int l = 0; l < m.column; l++)
				{
					sum = 0;
					for (int i = 0; i < column; i++)
					{
						sum = sum + (this->ptr[k*column + i]* m.ptr[l + m.column*i]);
					}
					newM.ptr[k * m.column + l] = sum;
				}
			}
			return newM;
		}
	};

	Matrix& operator*(T value)
	{
		for (int k = 0; k < row; k++)
		{
			for (int l = 0; l < column; l++)
			{
				this->ptr[k * column + l] = this->ptr[k * column + l] * value;
			}
		}
		return *this;
	};

	Matrix& operator/(T value)
	{
		for (int k = 0; k < row; k++)
		{
			for (int l = 0; l < column; l++)
			{
				this->ptr[k * column + l] = this->ptr[k * column + l] / value;
			}
		}
		return *this;
	};
};