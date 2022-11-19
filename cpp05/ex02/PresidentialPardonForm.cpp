#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm() :
	Form("presidential pardon", 25, 5, "unknown target")
{
	std::cout << "\e[32m" "Default PresidentialPardonForm constructor" "\e[m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	Form("presidential pardon", 25, 5, target)
{
	std::cout << "\e[32m" "Specialized PresidentialPardonForm constructor" "\e[m" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\e[31m" "PresidentialPardonForm destructor" "\e[m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	Form(other)
{
	std::cout << "\e[33m" "Copy PresidentialPardonForm constructor" "\e[m" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	Form::operator=(other);
	std::cout << "\e[36m" "PresidentialPardonForm copy assignment" "\e[m" << std::endl;
	return (*this);
}

void PresidentialPardonForm::executeImpl() const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
