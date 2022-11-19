#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <ostream>
#include "Form.hpp"

class Intern
{
	typedef Form* (Intern::*FormMaker)(std::string);

public:
	Intern();
	~Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);

	Form* makeForm(std::string name, std::string target);

private:
	Form* makePresidentialPardonForm(std::string target);
	Form* makeRobotomyRequestForm(std::string target);
	Form* makeShrubberyCreationForm(std::string target);
	static const std::string names[];
	static const FormMaker formMakers[];
};

#endif
