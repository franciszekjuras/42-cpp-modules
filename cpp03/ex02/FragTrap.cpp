#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap() :
	ClapTrap()
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "\e[32mDefault FragTrap constructor\e[m" << std::endl;
}

FragTrap::FragTrap(const std::string& name) :
	ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "\e[32mString FragTrap constructor\e[m" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "\e[31mFragTrap destructor\e[m" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) :
	ClapTrap()
{
	*this = other;
	std::cout << "\e[33mCopy FragTrap constructor\e[m" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	ClapTrap::operator=(other);
	std::cout << "\e[36mFragTrap copy assignment\e[m" << std::endl;
	return (*this);
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " shouts 'High fives guys!'" << std::endl;
}
