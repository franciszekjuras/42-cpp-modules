#include "Form.hpp"
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

Form::Form() :
	name("unknown"),
	gradeToSign(highestGrade),
	gradeToExec(highestGrade),
	formSigned(false)
{
	std::cout << "\e[32m" "Default Form constructor" "\e[m" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) :
	name(name),
	gradeToSign(gradeToSign),
	gradeToExec(gradeToExec),
	formSigned(false)
{
	validateGrade();
	std::cout << "\e[32m" "Specialized Form constructor" "\e[m" << std::endl;
}

Form::~Form()
{
	std::cout << "\e[31m" "Form destructor" "\e[m" << std::endl;
}

Form::Form(const Form& other) :
	name(other.name),
	gradeToSign(other.gradeToSign),
	gradeToExec(other.gradeToExec),
	formSigned(other.formSigned)
{
	std::cout << "\e[33m" "Copy Form constructor" "\e[m" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	formSigned = other.formSigned;
	std::cout << "\e[36m" "Form copy assignment" "\e[m" << std::endl;
	return (*this);
}

const std::string& Form::getName() const
{
	return (name);
}

int Form::getGradeToSign() const
{
	return (gradeToSign);
}

int Form::getGradeToExec() const
{
	return (gradeToExec);
}

bool Form::isSigned() const
{
	return (formSigned);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (formSigned)
		return;
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	formSigned = true;
}

void Form::validateGrade()
{
	if (gradeToSign > lowestGrade)
		throw GradeTooLowException();
	else if (gradeToSign < highestGrade)
		throw GradeTooHighException();
	if (gradeToExec > lowestGrade)
		throw GradeTooLowException();
	else if (gradeToExec < highestGrade)
		throw GradeTooHighException();
}

std::ostream& operator<<(std::ostream &out, const Form& form)
{
	out <<  (form.isSigned() ? "signed " : "not signed ") << form.getName() 
		<< " form, grade to sign " << form.getGradeToSign()
		<< ", grade to execute " << form.getGradeToExec();
	return (out);
}
