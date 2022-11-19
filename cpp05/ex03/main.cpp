#include <iostream>
#include "Form.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Intern intern;
	{
		Form* form = intern.makeForm("presidential pardon", "Danny");
		Bureaucrat ceo("Elon", 1);
		ceo.signForm(*form);
		ceo.executeForm(*form);
		delete form;
	}
	{
		std::cout << "---" << std::endl;
		Form* form = intern.makeForm("robotomy request", "Danny");
		delete form;
	}
	{
		std::cout << "---" << std::endl;
		Form* form = intern.makeForm("shrubbery creation", "Danny");
		delete form;		
	}
	{
		std::cout << "---" << std::endl;
		Form* noSuchForm = intern.makeForm("crazy request", "Danny");
		(void)noSuchForm;
	}
}
