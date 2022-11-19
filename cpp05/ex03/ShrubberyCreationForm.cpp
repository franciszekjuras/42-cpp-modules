#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() :
	Form("shrubbery creation", 145, 137, "unknown target")
{
	std::cout << "\e[32m" "Default ShrubberyCreationForm constructor" "\e[m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	Form("shrubbery creation", 145, 137, target)
{
	std::cout << "\e[32m" "Specialized ShrubberyCreationForm constructor" "\e[m" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\e[31m" "ShrubberyCreationForm destructor" "\e[m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	Form(other)
{
	std::cout << "\e[33m" "Copy ShrubberyCreationForm constructor" "\e[m" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	Form::operator=(other);
	std::cout << "\e[36m" "ShrubberyCreationForm copy assignment" "\e[m" << std::endl;
	return (*this);
}

void ShrubberyCreationForm::executeImpl() const
{
	std::ofstream out((getTarget() + "_shrubbery").c_str());
	if (!out)
	{
		std::cout << "Shrubbery creation on " << getTarget() << " failed" << std::endl;
		return;
	}
	out << "     /\\  /\\  /\\ \n" 
		<< "  /\\/  /\\  \\/  \\\n"
		<< " /  \\ / /\\ \\/  \\\n"
		<< " /  \\  /  \\\\/\\| \n"
		<< "  || @% || /  \\ \n"
		<< "    *@@*    || \n";
}
