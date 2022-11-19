#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
public:
	~Zombie();
	std::string& getName();
	const std::string& getName() const;
	void announce() const;

private:
	std::string name;
};

#endif
