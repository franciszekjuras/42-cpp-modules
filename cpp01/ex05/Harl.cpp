#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
	levelNames[0] = "debug";
	levelFunctions[0] = &Harl::debug;
	levelNames[1] = "info";
	levelFunctions[1] = &Harl::info;
	levelNames[2] = "warning";
	levelFunctions[2] = &Harl::warning;
	levelNames[3] = "error";
	levelFunctions[3] = &Harl::error;
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; ++i)
	{
		if (levelNames[i] == level)
		{
			(this->*levelFunctions[i])();
			break;
		}
	}
}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my "
	"7XL-double-cheese-triple-pickle-special-ketchup burger. "
	"I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
	"You didn’t put enough bacon in my burger! "
	"If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. "
	"I’ve been coming for years whereas you started "
	"working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! "
	"I want to speak to the manager now." << std::endl;
}
