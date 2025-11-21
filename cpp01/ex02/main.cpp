#include <string>
#include <iostream>

#define	RED		"\e[31;1m"
#define	RESET	"\e[0m"

int main(void)
{
	// Initialisation //
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	// Adress prints //
	std::cout << RED << "String memory address:\t\t" << RESET << &str << '\n';
	std::cout << RED << "PTR held memory address:\t" << RESET << stringPTR << '\n';
	std::cout << RED << "REF memory address:\t\t" << RESET << &stringREF << '\n';

	std::cout << std::endl;

	// Value prints //
	std::cout << RED << "String value:\t\t\t" << RESET << str << '\n';
	std::cout << RED << "Value pointed by PTR:\t\t" << RESET << *stringPTR << '\n';
	std::cout << RED << "Value pointed by REF:\t\t" << RESET << stringREF << '\n';

	return (0);
}
