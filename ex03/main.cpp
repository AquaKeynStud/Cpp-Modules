#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Intern.hpp"

/* -- COLORS -- */
#define ERROR       "\e[1;31m"
#define CATEGORY    "\e[1;38;2;255;180;70m"

using std::cout;

int main()
{
	cout << CATEGORY "━━━━━━━━━━━━ 🧪 TEST cpp05 ex03 - Interns 🧪 ━━━━━━━━━━━━\n" RESET;

	Intern intern;
	Bureaucrat boss("Boss", 1);
	
	std::srand(std::time(NULL));				// Injecting an arbitrary value as a seed

	cout << CATEGORY "\n━━━━━━━━━━━━ 🔅 Interns 🔅 ━━━━━━━━━━━━\n" RESET;

	AForm* robotomy = intern.makeForm("robotomy request", "intern");
	AForm* shrubbery = intern.makeForm("shrubbery creation", "hill");
	AForm* presidential = intern.makeForm("presidential pardon", "boss");

	cout << RESET;

	boss.signForm(*robotomy);
	boss.signForm(*shrubbery);
	boss.signForm(*presidential);

	cout << RESET;

	robotomy->execute(boss);
	shrubbery->execute(boss);
	presidential->execute(boss);

	cout << CATEGORY "\n━━━━━━━━━━━━ 🔅 Destruction 🔅 ━━━━━━━━━━━━\n" RESET;

	delete robotomy;
	delete shrubbery;
	delete presidential;

	return (0);
}
