#include "Zombie.hpp"
#include <iostream>

Zombie::~Zombie()
{
	std::cout << name << "\e[31m destructed\e[m" << std::endl;
}

std::string& Zombie::getName(){return (name);}

const std::string& Zombie::getName() const {return (name);}

void Zombie::announce() const
{
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
