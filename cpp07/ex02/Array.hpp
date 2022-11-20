#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <sstream>

template <typename T>
class Array
{
public:
	Array() : data(NULL), arrSize(0) {}

	Array(unsigned int n) : data(new T[n]), arrSize(n)
	{
		for (unsigned int i = 0; i < n; ++i)
			new(&data[i]) T;
	}

	~Array()
	{
		if (arrSize != 0)
			delete[] data;
	}

	Array(const Array& other) :
		data(new T[other.arrSize]), 
		arrSize(other.arrSize)
	{
		for (unsigned int i = 0; i < arrSize; ++i)
			data[i] = other.data[i];
	}

	Array& operator=(const Array& other)
	{
		T* tmpData = new T[other.arrSize];
		if (arrSize != 0)
		{
			delete[] data;
			data = NULL;
			arrSize = 0;
		}
		data = tmpData;
		arrSize = other.arrSize;
		for (unsigned int i = 0; i < arrSize; ++i)
			data[i] = other.data[i];
		return (*this);
	}

	const T& operator[](unsigned int i) const
	{
		throwIfIndexInvalid(i);
		return (data[i]);
	}

	T& operator[](unsigned int i)
	{
		throwIfIndexInvalid(i);
		return (data[i]);
	}

	unsigned int size() const
	{
		return (arrSize);
	}

private:
	void throwIfIndexInvalid(unsigned int i) const
	{
		if (i >= arrSize)
		{
			std::ostringstream errStr;
			errStr << "Index " << i << " is out of bounds [0, " << arrSize << ")";
			throw std::out_of_range(errStr.str().c_str());
		}
	}

	T* data;
	unsigned int arrSize;
};

#endif
