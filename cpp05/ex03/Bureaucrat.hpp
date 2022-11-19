#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>

class Form;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade = lowestGrade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);

	const std::string& getName() const;
	int getGrade() const;

	void increaseGrade();
	void decreaseGrade();
	void signForm(Form& form) const;
	void executeForm(const Form& form) const;

	static const int lowestGrade = 150;
	static const int highestGrade = 1;

protected:
	void validateGrade();

	const std::string name;
	int grade;

public:
	class GradeTooHighException : public std::exception {};
	class GradeTooLowException : public std::exception {};
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& bureaucrat);

#endif
