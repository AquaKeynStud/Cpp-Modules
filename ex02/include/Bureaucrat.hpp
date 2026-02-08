#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

/* -- Includes -- */
#include <string>

/* -- Typedefs -- */
typedef unsigned int uint;

/* -- Colors -- */
#ifndef RESET
# define RESET "\e[0m\n"
#endif

#ifndef ERROR
# define ERROR "\e[1;31m"
#endif

#ifndef INFO
# define INFO "\e[1;38;2;120;170;255m"
#endif

#define	CREATE	"\e[1;38;2;110;255;180m"
#define DESTROY	"\e[1;38;2;255;110;110m"

/* -- Class -- */
class AForm;

class Bureaucrat
{
private:
	const std::string	_name;
	unsigned int		_grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& toCopy);
	Bureaucrat(const std::string& name, uint grade);

	~Bureaucrat();

	Bureaucrat&	operator=(const Bureaucrat& other);

// Getters //
	const std::string&	getName(void) const;
	unsigned int		getGrade(void) const;

// Setters //
	void				demote(void);
	void				promote(void);

// Other methods //
	void				signForm(AForm& form);
	void				executeForm(AForm const & form) const;

// Exception //
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

/* -- Functions -- */
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
