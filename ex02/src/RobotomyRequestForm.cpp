#include <cstdlib>
#include <iostream>
#include "RobotomyRequestForm.hpp"

/* -- Usings -- */
using std::cout;

/* -- Class -- */
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("Dummy")
{
	cout << NEW_AFORM "👾 New RobotomyRequestForm created with [" << _target << "] as target 👾" RESET;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	cout << NEW_AFORM "👾 New RobotomyRequestForm created with [" << _target << "] as target 👾" RESET;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& toCopy)
	: AForm("RobotomyRequestForm", 72, 45), _target(toCopy._target)
{
	cout << NEW_AFORM "👾 New copy of a RobotomyRequestForm created 👾" RESET;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	cout << NO_AFORM "💀 RobotomyRequestForm destroyed 💀" RESET;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		_target = other._target;

	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (not getSigned())
	{
		cout << ERROR "🔖 The form must be signed to be executed 🔖" RESET;
		return ;
	}
	else if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException(executor.getGrade());

	cout << ROBOT "\e[3m🤖 * drilling noises * 🤖\n";

	if (std::rand() % 2)
		cout << _target << " has been robotomized ! 🔧" RESET;
	else
		cout << _target << " robotomization failed... 📴" RESET;

	return ;
}
