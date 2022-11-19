#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ScavTrap scav("Scav");
	scav.attack("Zombie");
	scav.takeDamage(7);
	scav.beRepaired(2);
	scav.takeDamage(6);
	scav.guardGate();

	std::cout << "Copy constructor example: " << std::endl;

	ScavTrap clone(scav);
	std::cout << "Calling clone:" << std::endl;
	clone.takeDamage(50);
	std::cout << "Calling original:" << std::endl;
	scav.attack("Zombie");
	
	std::cout << "Copy assignment example: " << std::endl;

	ScavTrap clone2;
	clone2 = scav;
	std::cout << "Calling clone:" << std::endl;
	clone2.takeDamage(30);
	std::cout << "Calling original:" << std::endl;
	scav.attack("Zombie");
}
