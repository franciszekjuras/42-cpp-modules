#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap() :
	name("Clappy"),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0)
{
	std::cout << "\e[32mDefault ClapTrap constructor\e[m" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) :
	name(name),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0)
{
	std::cout << "\e[32mString ClapTrap constructor\e[m" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\e[31mClapTrap destructor\e[m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "\e[33mCopy ClapTrap constructor\e[m" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "\e[36mClapTrap copy assignment\e[m" << std::endl;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	return (*this);
}


void ClapTrap::attack(const std::string& target)
{
	if (canTakeAction())
	{
		--energyPoints;
		std::cout << "ClapTrap " << name << " attacks "
			<< target << " causing \e[33;1m" << attackDamage
			<< "\e[m points of damage" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " cannot attack" << std::endl;
	printStats();
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << "ClapTrap " << name << " takes "
		<< amount << " points of damage" << std::endl;
	printStats();
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (canTakeAction())
	{
		--energyPoints;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " is repaired by "
			<< amount << " hit points" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " cannot be repaired" << std::endl;
	printStats();
}


bool ClapTrap::canTakeAction()
{
	if (hitPoints <= 0 || energyPoints <= 0)
		return (false);
	else
		return (true);
}

void ClapTrap::printStats()
{
	std::cout << "ClapTrap " << name << " has \e[32;1m" << hitPoints
		<< "\e[m hit points and \e[35;1m" << energyPoints
		<< "\e[m energy points" << std::endl;
}
