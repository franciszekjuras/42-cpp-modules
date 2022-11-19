#include "FragTrap.hpp"
#include <iostream>

int main()
{
	FragTrap scav("Scav");
	scav.attack("Zombie");
	scav.takeDamage(7);
	scav.beRepaired(2);
	scav.takeDamage(6);
	scav.highFivesGuys();

	std::cout << "Copy constructor example: " << std::endl;

	FragTrap clone(scav);
	std::cout << "Calling clone:" << std::endl;
	clone.takeDamage(50);
	std::cout << "Calling original:" << std::endl;
	scav.attack("Zombie");
	
	std::cout << "Copy assignment example: " << std::endl;

	FragTrap clone2;
	clone2 = scav;
	std::cout << "Calling clone:" << std::endl;
	clone2.takeDamage(30);
	std::cout << "Calling original:" << std::endl;
	scav.attack("Zombie");
}
