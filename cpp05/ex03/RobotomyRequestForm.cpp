#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <string>
#include <sys/time.h>

RobotomyRequestForm::RobotomyRequestForm() :
	Form("robotomy request", 72, 45, "unknown target")
{
	std::cout << "\e[32m" "Default RobotomyRequestForm constructor" "\e[m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form("robotomy request", 72, 45, target)
{
	std::cout << "\e[32m" "Specialized RobotomyRequestForm constructor" "\e[m" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\e[31m" "RobotomyRequestForm destructor" "\e[m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	Form(other)
{
	std::cout << "\e[33m" "Copy RobotomyRequestForm constructor" "\e[m" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	Form::operator=(other);
	std::cout << "\e[36m" "RobotomyRequestForm copy assignment" "\e[m" << std::endl;
	return (*this);
}

void RobotomyRequestForm::executeImpl() const
{
	std::cout << "Drir!!1!!1lrwer!!!lwhierizzlzjzilwierhiwlz" << std::endl;
	struct timeval tm;
	gettimeofday(&tm, NULL);
	if (tm.tv_usec % 2 == 0)
		std::cout << getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << getTarget() << " robotomization failed" << std::endl;
}
