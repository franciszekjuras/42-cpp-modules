#include "Intern.hpp"
#include <iostream>
#include <string>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const std::string Intern::names[] = 
	{
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

const Intern::FormMaker Intern::formMakers[] =
	{
		&Intern::makePresidentialPardonForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makeShrubberyCreationForm
	};

Intern::Intern()
{
	std::cout << "\e[32m" "Default Intern constructor" "\e[m" << std::endl;
}

Intern::~Intern()
{
	std::cout << "\e[31m" "Intern destructor" "\e[m" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "\e[33m" "Copy Intern constructor" "\e[m" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	std::cout << "\e[36m" "Intern copy assignment" "\e[m" << std::endl;
	return (*this);
}

Form* Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form* Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form* Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form* Intern::makeForm(std::string name, std::string target)
{
	for (int i = 0; i < 3; ++i)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates " << name << " form" << std::endl;
			return ((this->*formMakers[i])(target));
		}
	}
	std::cout << "Intern cannot create " << name << " form" << std::endl;
	return (NULL);
}
