#include "WrongCat.hpp"
#include <iostream>
#include <string>

WrongCat::WrongCat() :
	WrongAnimal()
{
	type = "WrongCat";
	std::cout << "\e[32mDefault WrongCat constructor\e[m" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "\e[31mCat destructor\e[m" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) :
	WrongAnimal(other)
{
	std::cout << "\e[33mCopy WrongCat constructor\e[m" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	WrongAnimal::operator=(other);
	std::cout << "\e[36mCat copy assignment\e[m" << std::endl;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Miauuu" << std::endl;
}
