#ifndef AFORM_HPP
# define AFORM_HPP

/* -- Includes -- */
#include <string>
#include "Bureaucrat.hpp"

/* -- Colors -- */
#define	NEW_AFORM	"\e[1;38;2;150;255;240m"
#define	NO_AFORM		"\e[1;38;2;255;205;150m"

/* -- Class -- */
class AForm
{
private:
	const std::string	_name;
	bool				_signed;
	const unsigned int	_sign_grade;
	const unsigned int	_exec_grade;

protected:
	bool	canExec(const Bureaucrat& executor) const;

public:
	AForm();
	AForm(const AForm& toCopy);
	AForm(const std::string& name, uint sign, uint exec);

	virtual ~AForm();

	AForm& operator=(const AForm& other);

// Setters //
	void				beSigned(const Bureaucrat& bureaucrat);

// Getters //
	const std::string&	getName(void) const;
	bool				getSigned(void) const;
	unsigned int		getSignGrade(void) const;
	unsigned int		getExecGrade(void) const;

// Methods //
	virtual void		execute(Bureaucrat const & executor) const = 0;

// Exceptions //
	class GradeTooLowException : public std::exception
	{
		std::string	_msg;
		public:
			GradeTooLowException(unsigned int grade);
			virtual ~GradeTooLowException() throw();
			virtual const char*	what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		std::string	_msg;
		public:
			GradeTooHighException(unsigned int grade);
			virtual ~GradeTooHighException() throw();
			virtual const char*	what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& Aform);

#endif
