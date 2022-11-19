#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <ostream>

class Bureaucrat;

class Form
{
public:
	Form();
	Form(std::string name, int gradeToSign = highestGrade, int gradeToExec = highestGrade);
	~Form();
	Form(const Form& other);
	Form& operator=(const Form& other);

	const std::string& getName() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat& bureaucrat);

	static const int lowestGrade = 150;
	static const int highestGrade = 1;

private:
	void validateGrade();

	const std::string name;
	const int gradeToSign;
	const int gradeToExec;
	bool formSigned;

public:
	class GradeTooHighException : public std::exception {};
	class GradeTooLowException : public std::exception {};
};

std::ostream& operator<<(std::ostream &out, const Form& form);

#endif
