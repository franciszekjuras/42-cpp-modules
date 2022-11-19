#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
{
typedef void (Harl::*HarlMsg)();

public:
	Harl();
	void complain(std::string level);

private:
	void debug();
	void info();
	void warning();
	void error();

	std::string levelNames[4];
	HarlMsg levelFunctions[4];
};

#endif
