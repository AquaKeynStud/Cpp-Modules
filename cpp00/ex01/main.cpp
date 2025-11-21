#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phone;
	std::string	entry;

	std::cout << "\e[36;1m\t╭━━━═╕ ⛲️ Welcome to your PhoneBook ! 🎍 ╒═━━━╮\n";
	std::cout << "\t|               \e[0;1m🛟 COMMANDS 🛟\e[36;1m                |\n";
	std::cout << "\t|               \e[0;1m  • ADD 🆕    \e[36;1m                |\n";
	std::cout << "\t|               \e[0;1m  • SEARCH 🔍 \e[36;1m                |\n";
	std::cout << "\t|               \e[0;1m  • EXIT 🚧   \e[36;1m                |\n";
	std::cout << "\t╰━━━━━━━━══════╛ 🍂 光 • 線 🪼 ╘══════━━━━━━━━╯\e[0m\n" << std::endl;

	while (true)
	{
		std::cout << "\e[1;3m📇 PhoneBook ➦ \e[0m";

		wrapGetline(entry);

		if (entry == "ADD")
			phone.AddContact();
		else if (entry == "SEARCH")
			phone.SearchContact();
		else if (entry == "EXIT")
			break;
		else
		{
			std::cout << "\e[31;1m🈲 Error: Please enter a valid command or EXIT 🈲\e[0m" << std::endl;
			continue;
		}
	}
	
	return (0);
}