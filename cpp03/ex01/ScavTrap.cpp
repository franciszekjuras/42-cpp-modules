#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap() :
	ClapTrap()
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "\e[32mDefault ScavTrap constructor\e[m" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) :
	ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "\e[32mString ScavTrap constructor\e[m" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\e[31mScavTrap destructor\e[m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) :
	ClapTrap()
{
	*this = other;
	std::cout << "\e[33mCopy ScavTrap constructor\e[m" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	ClapTrap::operator=(other);
	std::cout << "\e[36mScavTrap copy assignment\e[m" << std::endl;
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (canTakeAction())
	{
		--energyPoints;
		std::cout << "ScavTrap " << name << " attacks "
			<< target << " causing \e[33;1m" << attackDamage
			<< "\e[m points of damage" << std::endl;
	}
	else
		std::cout << "ScavTrap " << name << " cannot attack" << std::endl;
	printStats();
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in gate-keeper mode" << std::endl;
}
