#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

/* -- Includes -- */
#include <string>

/* -- Colors -- */
#define	RESET	"\033[0m\n"
#define	CREATE	"\033[1;38;2;110;255;180m"
#define DESTROY	"\033[1;38;2;255;110;110m"

/* -- Class -- */
class Bureaucrat
{
private:
	const std::string	_name;
	unsigned int		_grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& toCopy);
	Bureaucrat(const std::string& name, unsigned int grade);

	~Bureaucrat();

	Bureaucrat&	operator=(const Bureaucrat& other);

	// Getters //
	const std::string&	getName(void) const;
	unsigned int		getGrade(void) const;

	// Setters //
	void				demote(void);
	void				promote(void);

	// Inner Exception //
	class GradeTooLowException : public std::exception {
		public:
			GradeTooLowException();
			virtual ~GradeTooLowException() throw();
			virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
		public:
			GradeTooHighException();
			virtual ~GradeTooHighException() throw();
			virtual const char* what() const throw();
	};
};

#endif
