#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap clappy("Clappy");
	clappy.attack("Zombie");
	clappy.takeDamage(7);
	clappy.beRepaired(2);
	clappy.takeDamage(6);
	clappy.attack("Zombie");
	clappy.beRepaired(100);

	ClapTrap clippy("Clippy");
	for(int i = 0; i < 8; ++i)
		clippy.attack("Zombie");
	clippy.beRepaired(2);
	clippy.beRepaired(3);
	clippy.beRepaired(4);
	clippy.attack("Zombie");

	ClapTrap clappyClone(clappy);
	clappyClone.attack("Zombie");

	ClapTrap clippyClone;
	clippyClone = clippy;
	clippy.attack("Zombie");
}
