#include <iostream>
#include "iter.hpp"

template <typename T>
void myPrint(T& arg)
{
	std::cout << "hello, " << arg << " it's me!" << std::endl;
}

void incr10(int& v)
{
	v += 10;
}

int main()
{
	std::string arr[] = {"aaa", "bb", "c"};
	iter(arr, 3, &myPrint);
	
	int data[] = {0, 10, 42, 1000};
	iter(data, 4, &incr10);
	iter(data, 4, &myPrint);
}