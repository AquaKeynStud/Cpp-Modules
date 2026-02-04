/* -- Includes -- */
#include <sstream>
#include <iostream>
#include "Form.hpp"

/* -- usings -- */
using std::cout;

/* -- Methods -- */
Form::Form() : _name("Default Form"), _signed(false), _sign_grade(150), _exec_grade(150)
{
	cout << NEW_FORM "📜 New default Form created 📜" RESET;
}

Form::Form(const Form& toCopy)
	: _name(toCopy._name),
	_signed(toCopy._signed),
	_sign_grade(toCopy._sign_grade),
	_exec_grade(toCopy._exec_grade)
{
	cout << NEW_FORM "📜 New copy of Form [" <<  toCopy._name << "] created 📜" RESET;
}

Form::Form(const std::string& name, uint grade, uint exec)
	: _name(name), _signed(false), _sign_grade(grade), _exec_grade(exec)
{
	if (grade < 1 or exec < 1)
		grade < exec ? throw GradeTooLowException(grade) : throw GradeTooLowException(exec);
	else if (grade > 1 or exec > 1)
		grade > exec ? throw GradeTooHighException(grade) : throw GradeTooHighException(exec);

	cout << NEW_FORM "📜 New default Form created 📜" RESET;
}

Form::~Form() { cout << NO_FORM "📌 Form named [" << _name << "] destroyed 📌" RESET; }

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_signed = other._signed;

	return (*this);
}

/* -- Exceptions -- */
Form::GradeTooLowException::GradeTooLowException(unsigned int grade)
{
	std::ostringstream	oss;
	oss << ERROR "The passed grade: " << grade << "is too low" RESET;
	_msg = oss.str();
}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Form::GradeTooLowException::what() const throw()
{
	return (_msg.c_str());
}

Form::GradeTooHighException::GradeTooHighException(unsigned int grade)
{
	std::ostringstream	oss;
	oss << ERROR "The passed grade: " << grade << "is too high" RESET;
	_msg = oss.str();
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

const char* Form::GradeTooHighException::what() const throw()
{
	return (_msg.c_str());
}

/* -- Other functions -- */
std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << form.getName();
	os << (form.getSigned() ? "is signed" : "is unsigned");
	os << "Grade required to sign: " << form.getSignGrade() << ". ";
	os << "Grade required to sign: " << form.getSignGrade() << ".";
	return (os);
}
