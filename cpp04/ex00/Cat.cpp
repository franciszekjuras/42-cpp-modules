#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat() :
	Animal()
{
	type = "Cat";
	std::cout << "\e[32mDefault Cat constructor\e[m" << std::endl;
}

Cat::~Cat()
{
	std::cout << "\e[31mCat destructor\e[m" << std::endl;
}

Cat::Cat(const Cat& other) :
	Animal(other)
{
	std::cout << "\e[33mCopy Cat constructor\e[m" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	Animal::operator=(other);
	std::cout << "\e[36mCat copy assignment\e[m" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Miauuu" << std::endl;
}
