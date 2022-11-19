#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
	Zombie* horde = zombieHorde(6, "Stefan");
	for (int i = 0; i < 6; ++i)
		horde[i].announce();
	delete[] horde;
	return (0);
}
