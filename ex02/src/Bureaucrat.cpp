/* -- Includes -- */
#include <iostream>
#include "AForm.hpp"

/* -- Class definition -- */
Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150)
{
	std::cout << CREATE "❇️  Unknown Bureaucrat created successfully ! ❇️" RESET;
}

Bureaucrat::Bureaucrat(const Bureaucrat& toCopy) : _name(toCopy._name), _grade(toCopy._grade)
{
	std::cout << CREATE "🦠 Bureaucrat copied successfully ! 🦠" RESET;
}

Bureaucrat::Bureaucrat(const std::string& name, uint grade) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	
	std::cout << CREATE "❇️  Bureaucrat " << _name << " created successfully ! ❇️" RESET;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << DESTROY "🧨 Bureaucrat " << _name << " destroyed... 🧨" RESET ;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		_grade = other._grade;

	return (*this);
}


/* -- Getters -- */
const std::string& Bureaucrat::getName() const { return (_name); }

unsigned int Bureaucrat::getGrade() const { return (_grade); }

/* -- Setters -- */
void Bureaucrat::demote()
{
	if (_grade >= 150)
		throw GradeTooLowException();

	_grade++;
}

void Bureaucrat::promote()
{
	if (_grade <= 1)
		throw GradeTooHighException();

	_grade--;
}

/* -- Other methods -- */
void Bureaucrat::signForm(AForm& form)
{
	if (form.getSigned())
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because the form is already signed.\n";
		return ;
	}

	form.beSigned(*this);

	if (form.getSigned())
		std::cout << _name << " signed " << form.getName() << ".\n";
	else
		std::cout << _name << " couldn't sign " << form.getName() << " because his grade is too low.\n";
}

void Bureaucrat::executeForm(const AForm& form) const
{
	if (!form.execute(*this))
	{
		std::cout << ERROR "Bureaucrat [" << _name;
		std::cout << "] failed to execute a " << form.getName() << "." RESET;
		return ;
	}
	std::cout << form.getName() << " successfully executed by Bureaucrat [" << _name << "]." RESET;
}

/* -- Exceptions definitions -- */
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade error: Grade too low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade error: Grade too high");
}

/* -- Other functions -- */
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << "🌐 \e[1m";
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}
