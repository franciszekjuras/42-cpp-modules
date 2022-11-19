#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "\e[32mDefault Brain constructor\e[m" << std::endl;
}

Brain::~Brain()
{
	std::cout << "\e[31mBrain Destructor\e[m" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "\e[33mCopy Brain constructor\e[m" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "\e[36mBrain copy assignment\e[m" << std::endl;
	for (int i = 0; i < 100; ++i)
		ideas[i] = other.ideas[i];
	return (*this);
}

const std::string* Brain::getIdeas() const
{
	return (ideas);
}

std::string* Brain::getIdeas()
{
	return (ideas);
}
