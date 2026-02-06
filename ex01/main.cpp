#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

/* -- COLORS -- */
#define ERROR       "\e[1;31m"
#define CATEGORY    "\e[1;38;2;255;180;70m"

using std::cout;

int main()
{
	cout << CATEGORY "🧪 TEST cpp05 ex01 - Form 🧪\n" RESET;

	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat intern("Intern", 150);
		Form contract("Contract", 50, 25);
		Form secret("Secret", 1, 1);

		cout << "\n\e[1m______________________________________________________\n" RESET;

		cout << CATEGORY "\n🔅 Tests d'affichage 🔅\n" RESET;

		/* -- CONSTRUCTEURS OK -- */
		try
		{
			cout << boss << RESET;
			cout << intern << RESET;
			cout << contract << RESET;
			cout << secret << RESET;
		}
		catch (std::exception& e)
		{
			cout << ERROR "❌ Exception inattendue: " << e.what() << RESET;
		}

		cout << "\n\e[1m______________________________________________________\n" RESET;

		cout << CATEGORY "\n🔅 Signature des formulaires 🔅\n" RESET;

		cout << contract << RESET;
		cout << secret << RESET;

		try
		{
			boss.signForm(contract);
			intern.signForm(contract);
			boss.signForm(contract);
		}
		catch(const std::exception& e)
		{
			cout << ERROR "❌ Exception inattendue: " << e.what() << RESET;
		}

		try
		{
			intern.signForm(secret);
		}
		catch(const std::exception& e)
		{
			cout << ERROR "📛 Exception attrapée (comportement attendu): " << e.what() << RESET;
		}

		try
		{
			boss.signForm(secret);
		}
		catch(const std::exception& e)
		{
			cout << ERROR "📛 Exception attrapée (comportement attendu): " << e.what() << RESET;
		}

		cout << contract << RESET;
		cout << secret << RESET;

		cout << "\n\e[1m______________________________________________________\n" RESET;

		/* -- CONSTRUCTEURS KO -- */
		cout << CATEGORY "\n🔅 Création invalide de Form 🔅\n" RESET;

		try
		{
			Form tooHigh("TooHigh", 0, 10);
			(void)tooHigh;
		}
		catch (const std::exception& e)
		{
			cout << ERROR "📛 Exception attrapée (comportement attendu): " << e.what() << RESET;
		}

		try
		{
			Form tooLow("TooLow", 10, 151);
			(void)tooLow;
		}
		catch (const std::exception& e)
		{
			cout << ERROR "📛 Exception attrapée (comportement attendu): " << e.what() << RESET;
		}

		cout << "\n\e[1m______________________________________________________\n" RESET;
	}

	cout << CATEGORY "\n🎉 Tous les tests sont passés !" RESET;
	return (0);
}
