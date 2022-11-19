#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog() :
	Animal(),
	brain(new Brain())
{
	type = "Dog";
	std::cout << "\e[32mDefault Dog constructor\e[m" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "\e[31mDog destructor\e[m" << std::endl;
}

Dog::Dog(const Dog& other) :
	Animal(other),
	brain(new Brain(*other.brain))
{
	std::cout << "\e[33mCopy Dog constructor\e[m" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	Animal::operator=(other);
	*brain = *other.brain;
	std::cout << "\e[36mDog copy assignment\e[m" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Hau hau" << std::endl;
}

const Brain& Dog::getBrain() const
{
	return (*brain);
}

Brain& Dog::getBrain()
{
	return (*brain);
}
