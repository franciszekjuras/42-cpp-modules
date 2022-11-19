#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		Form form;
		Form appl("application", 100, 120);
		std::cout << appl << std::endl;
	}
	std::cout << "---" << std::endl;
	{
		try {Form sfag("sfag", -10, 100);}
		catch (const Form::GradeTooHighException& e)
			{ std::cout << "\e[33m" "Form's grade is too high" "\e[m" << std::endl; }
		try	{Form yolo("yolo", 1000, -1);}
		catch (const Form::GradeTooLowException& e)
			{ std::cout << "\e[33m" "Form's grade is too low" "\e[m" << std::endl; }
	}
	std::cout << "---" << std::endl;
	{
		Form appl("application", 100, 120);
		Bureaucrat danny("Danny", 90);
		appl.beSigned(danny);
		std::cout << appl << std::endl;
		Form complain("complain", 20, 3);
		try	{complain.beSigned(danny);}
		catch (const Form::GradeTooLowException& e)
			{ std::cout << "\e[33m" "Danny's grade is too low to sign the form" "\e[m" << std::endl; }
	}
	std::cout << "---" << std::endl;
	{
		Form appl("application", 100, 120);
		Bureaucrat danny("Danny", 90);
		danny.signForm(appl);
		std::cout << appl << std::endl;
		Form complain("complain", 20, 3);
		danny.signForm(complain);
		std::cout << complain << std::endl;
	}
}
