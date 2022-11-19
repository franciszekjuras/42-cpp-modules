#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	Zombie* stefan = newZombie("Stefan");
	randomChump("Chump");
	stefan->announce();
	delete stefan;
	return (0);
}
