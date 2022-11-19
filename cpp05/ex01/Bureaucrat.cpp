#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include "Form.hpp"

Bureaucrat::Bureaucrat() :
	name("Noname"),
	grade(lowestGrade)
{
	std::cout << "\e[32m" "Default Bureaucrat constructor" "\e[m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) :
	name(name),
	grade(grade)
{
	validateGrade();
	std::cout << "\e[32m" "Specialized Bureaucrat constructor" "\e[m" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[31m" "Bureaucrat destructor" "\e[m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	name(other.name),
	grade(other.grade)
{
	std::cout << "\e[33m" "Copy Bureaucrat constructor" "\e[m" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	grade = other.grade;
	std::cout << "\e[36m" "Bureaucrat copy assignment" "\e[m" << std::endl;
	return (*this);
}

const std::string& Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::increaseGrade()
{
	if (grade == highestGrade)
		throw GradeTooHighException();
	--grade;
}

void Bureaucrat::decreaseGrade()
{
	if (grade == lowestGrade)
		throw GradeTooLowException();
	++grade;
}

void Bureaucrat::signForm(Form& form) const
{
	if (form.isSigned())
	{
		std::cout << name << " cannot sign " << form.getName() 
			<< " form because it's already signed" << std::endl;
		return;
	}
	try {form.beSigned(*this);}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << name << " cannot sign " << form.getName() 
			<< " form because of too low grade" << std::endl;
		return;
	}
	std::cout << name << " signed " << form.getName() << " form" << std::endl;
}

void Bureaucrat::validateGrade()
{
	if (grade > lowestGrade)
		throw GradeTooLowException();
	else if (grade < highestGrade)
		throw GradeTooHighException();
}


std::ostream& operator<<(std::ostream &out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", grade " << bureaucrat.getGrade();
	return (out);
}
