#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

/* -- Includes -- */
#include "AForm.hpp"

/* -- Colors -- */
#define	ROBOT	"\e[1;38;2;150;150;150m"

/* -- Class -- */
class RobotomyRequestForm : public AForm
{
private:
	std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& toCopy);

	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	bool	execute(const Bureaucrat& executor) const;
};

#endif
