#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int> emptyArr;
	Array<int> arr(5);

	arr[0] = 5;
	arr[2] = 3;
	const Array<int>& arrCRef = arr;
	for (unsigned int i = 0; i < arrCRef.size(); ++i)
		std::cout << arrCRef[i] << std::endl;
	std::cout << "---" << std::endl;
	try {arr[12] = 3;}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---" << std::endl;
	Array<int> arrCopy(arr);
	for (unsigned int i = 0; i < arrCopy.size(); ++i)
		std::cout << arrCopy[i] << std::endl;
	std::cout << "---" << std::endl;
	arrCopy[3] = 999;
	std::cout << arrCopy[3] << std::endl;
	std::cout << arr[3] << std::endl;
	std::cout << "---" << std::endl;
	Array<int> otherArr(13);
	otherArr = arrCRef;
	for (unsigned int i = 0; i < otherArr.size(); ++i)
		std::cout << otherArr[i] << std::endl;
	std::cout << "---" << std::endl;
	otherArr[3] = 999;
	std::cout << otherArr[3] << std::endl;
	std::cout << arr[3] << std::endl;
}