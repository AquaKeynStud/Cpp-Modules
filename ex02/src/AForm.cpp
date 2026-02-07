/* -- Includes -- */
#include <sstream>
#include <iostream>
#include "AForm.hpp"

/* -- usings -- */
using std::cout;

/* -- Constructors -- */
AForm::AForm() : _name("Default AForm"), _signed(false), _sign_grade(150), _exec_grade(150) {}

AForm::AForm(const AForm& toCopy)
	: _name(toCopy._name),
	_signed(toCopy._signed),
	_sign_grade(toCopy._sign_grade),
	_exec_grade(toCopy._exec_grade)
{}

AForm::AForm(const std::string& name, uint grade, uint exec)
	: _name(name), _signed(false), _sign_grade(grade), _exec_grade(exec)
{
	if (grade < 1 or exec < 1)
		grade < exec ? throw GradeTooLowException(grade) : throw GradeTooLowException(exec);
	else if (grade > 150 or exec > 150)
		grade > exec ? throw GradeTooHighException(grade) : throw GradeTooHighException(exec);
}

/* -- Destructor -- */
AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		_signed = other._signed;

	return (*this);
}

/* -- Setters -- */
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (_signed)
		return ;

	if (bureaucrat.getGrade() > _sign_grade)
		throw GradeTooLowException(bureaucrat.getGrade());

	_signed = true;
}

/* -- Getters -- */
bool AForm::getSigned() const { return (_signed); }

const std::string& AForm::getName() const { return (_name); }

unsigned int AForm::getSignGrade() const { return (_sign_grade); }

unsigned int AForm::getExecGrade() const { return (_exec_grade); }

/* -- Exceptions -- */
AForm::GradeTooLowException::GradeTooLowException(unsigned int grade)
{
	std::ostringstream	oss;
	oss << "The passed grade: " << grade << " is too low";
	_msg = oss.str();
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

const char* AForm::GradeTooLowException::what() const throw() { return (_msg.c_str()); }

AForm::GradeTooHighException::GradeTooHighException(unsigned int grade)
{
	std::ostringstream	oss;
	oss << "The passed grade: " << grade << " is too high";
	_msg = oss.str();
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

const char* AForm::GradeTooHighException::what() const throw() { return (_msg.c_str()); }

/* -- Other functions -- */
std::ostream& operator<<(std::ostream& os, const AForm& Aform)
{
	os << "🌐 \e[1m";
	os << Aform.getName();
	os << (Aform.getSigned() ? " is signed. " : " is unsigned. ");
	os << "Grade required to sign: " << Aform.getSignGrade() << ". ";
	os << "Grade required to execute it: " << Aform.getExecGrade() << ".";
	return (os);
}
