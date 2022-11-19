#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		ShrubberyCreationForm form("Star");
		Bureaucrat ceo("Elon", 1);
		form.beSigned(ceo);
		form.execute(ceo);
	}
	{
		std::cout << "---" << std::endl;
		ShrubberyCreationForm form("Kevin");
		Bureaucrat boss("Michael", 12);
		Bureaucrat sales("Jim", 138);
		Bureaucrat intern("Ryan", 148);
		try	{form.beSigned(intern);}
		catch (const Form::GradeTooLowException& e)
			{ std::cout << "\e[33m" "Intern's grade is too low to sign the form" "\e[m" << std::endl; }
		try	{form.execute(boss);}
		catch (const Form::NotSigned& e)
			{ std::cout << "\e[33m" "Form's cannot be executed because it's not signed" "\e[m" << std::endl; }
		form.beSigned(sales);
		try	{form.execute(sales);}
		catch (const Form::GradeTooLowException& e)
			{ std::cout << "\e[33m" "Jim's grade is too low to execute the form" "\e[m" << std::endl; }
		form.execute(boss);
	}
	{
		std::cout << "---" << std::endl;
		ShrubberyCreationForm form("Kevin");
		Bureaucrat boss("Michael", 12);
		Bureaucrat sales("Jim", 138);
		Bureaucrat intern("Ryan", 148);
		intern.signForm(form);
		boss.executeForm(form);
		sales.signForm(form);
		sales.executeForm(form);
		boss.executeForm(form);
	}
	{
		std::cout << "---" << std::endl;
		RobotomyRequestForm form("Pam");
		Bureaucrat boss("Michael", 12);
		Bureaucrat sales("Jim", 70);
		sales.signForm(form);
		sales.executeForm(form);
		for (int i = 0; i < 6; ++i)
			boss.executeForm(form);
	}
	{
		std::cout << "---" << std::endl;
		PresidentialPardonForm form("Dwight");
		Bureaucrat boss("Michael", 5);
		Bureaucrat sales("Jim", 19);
		sales.signForm(form);
		sales.executeForm(form);
		boss.executeForm(form);
	}
}
