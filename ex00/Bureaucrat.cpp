/* -- Includes -- */
#include <iostream>
#include "Bureaucrat.hpp"

/* -- Class definition -- */
Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150)
{
	std::cout << CREATE "❇️  Unknown Bureaucrat created successfully ! ❇️" RESET;
}

Bureaucrat::Bureaucrat(const Bureaucrat& toCopy) : _name(toCopy._name), _grade(toCopy._grade)
{
	std::cout << CREATE "🦠 Bureaucrat copied successfully ! 🦠" RESET;
}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) : _name(name), _grade(grade)
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

/* -- Exceptions definitions -- */
Bureaucrat::GradeTooLowException::GradeTooLowException() {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade error: Grade too low");
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade error: Grade too high");
}
