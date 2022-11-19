#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal() :
	type("Unknown type")
{
	std::cout << "\e[32mDefault Animal constructor\e[m" << std::endl;
}

Animal::~Animal()
{
	std::cout << "\e[31mAnimal destructor\e[m" << std::endl;
}

Animal::Animal(const Animal& other) :
	type(other.type)
{
	std::cout << "\e[33mCopy Animal constructor\e[m" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	type = other.type;
	std::cout << "\e[36mAnimal copy assignment\e[m" << std::endl;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Unknown animal sound" << std::endl;
}

const std::string& Animal::getType() const
{
	return (type);
}
