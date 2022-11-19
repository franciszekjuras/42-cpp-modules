#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	{
		Bureaucrat danny;
		Bureaucrat ruby("Ruby", 100);
		std::cout << danny.getName() << " " << danny.getGrade() << std::endl;
		std::cout << ruby.getName() << " " << ruby.getGrade() << std::endl;
		std::cout << danny << std::endl;
		std::cout << ruby << std::endl;
	}

	try {Bureaucrat sfag("Sfag", -10);}
	catch (const Bureaucrat::GradeTooHighException& e)
		{ std::cout << "\e[33m" "Bureaucrat's grade is too high" "\e[m" << std::endl; }
	try	{Bureaucrat yolo("Yolo", 1000);}
	catch (const Bureaucrat::GradeTooLowException& e)
		{ std::cout << "\e[33m" "Bureaucrat's grade is too low" "\e[m" << std::endl; }

	{
		Bureaucrat intern("Johnny", Bureaucrat::lowestGrade - 1);
		intern.decreaseGrade();
		try {intern.decreaseGrade();}
		catch (const Bureaucrat::GradeTooLowException& e)
			{std::cout << "\e[33m" "Intern's grade cannot be lower" "\e[m" << std::endl;}
		std::cout << intern << std::endl;

		Bureaucrat ceo("Elon", Bureaucrat::highestGrade + 1);
		ceo.increaseGrade();
		try {ceo.increaseGrade();}
		catch (const Bureaucrat::GradeTooHighException& e)
			{std::cout << "\e[33m" "Elon's grade cannot be higher" "\e[m" << std::endl;}
		std::cout << ceo << std::endl;
	}
}
