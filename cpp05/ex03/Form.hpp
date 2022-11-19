#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <ostream>

class Bureaucrat;

class Form
{
public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExec, std::string target);
	virtual ~Form();
	Form(const Form& other);
	Form& operator=(const Form& other);

	const std::string& getName() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	const std::string& getTarget() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat& bureaucrat);
	void execute(const Bureaucrat& bureaucrat) const;

	static const int lowestGrade = 150;
	static const int highestGrade = 1;

private:
	virtual void executeImpl() const = 0;
	void validateGrade();

	const std::string name;
	const int gradeToSign;
	const int gradeToExec;
	std::string target;
	bool formSigned;

public:
	class GradeTooHighException : public std::exception {};
	class GradeTooLowException : public std::exception {};
	class NotSigned : public std::exception {};
};

std::ostream& operator<<(std::ostream &out, const Form& form);

#endif
