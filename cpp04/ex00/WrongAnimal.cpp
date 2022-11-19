#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal() :
	type("Unknown type")
{
	std::cout << "\e[32mDefault WrongAnimal constructor\e[m" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\e[31mAnimal destructor\e[m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) :
	type(other.type)
{
	std::cout << "\e[33mCopy WrongAnimal constructor\e[m" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	type = other.type;
	std::cout << "\e[36mAnimal copy assignment\e[m" << std::endl;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Unknown WrongAnimal sound" << std::endl;
}

const std::string& WrongAnimal::getType() const
{
	return (type);
}
