#include "utils.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): _index(0) {}
PhoneBook::~PhoneBook() {}

/* -- Private Methods -- */

void PhoneBook::AskAndSet(Contact &contact, const std::string &prompt, void (Contact::*setter)(const std::string &))
{
	std::string	entry;

	std::cout << "\e[35m" << prompt << "\e[0m";

	while (true)
	{
		wrapGetline(entry);

		if (entry.empty())
		{
			std::cout << "\e[31;1m🈲 Error: field cannot be empty. Please try again 🈲\e[0m\n";
			std::cout << "\e[35m" << prompt << "\e[0m";
			continue;
		}

		if (prompt == "Phone number: " && !isPhone(entry))
		{
			std::cout << "\e[31;1m🈲 Error: field must contain numbers only. Please try again 🈲\e[0m\n";
			std::cout << "\e[35m" << prompt << "\e[0m";
			continue;
		}

		break;
	}

	(contact.*setter)(entry);
}

bool PhoneBook::DisplayPhoneBook()
{
	if (_index == 0)
	{
		std::cout << "\e[33;1m🔆 PhoneBook is empty ! Please use ADD command first.🔆\e[0m\n";
		return (false);
	}

	std::cout << "\e[1m_____________________________________________\n";
	std::cout << "|     index|first name| last name|  nickname|\n";
	std::cout << "_____________________________________________\n";
	for (int i = 0; i < 8; i++)
	{
		if (i >= _index)
			break;
		std::cout << "|" + std::string(9, ' ') << i << "|";
		valuePadding(phone_book[i].getFirstName());
		valuePadding(phone_book[i].getLastName());
		valuePadding(phone_book[i].getNickname());
		std::cout << '\n';
	}
	std::cout << "_____________________________________________\e[0m\n" << std::endl;
	return (true);
}

/* -- Public Methods -- */

void PhoneBook::AddContact()
{
	Contact		new_contact;

	AskAndSet(new_contact, "First name: ", &Contact::setFirstName);
	AskAndSet(new_contact, "Last name: ", &Contact::setLastName);
	AskAndSet(new_contact, "Nickname: ", &Contact::setNickname);
	AskAndSet(new_contact, "Phone number: ", &Contact::setPhoneNumber);
	AskAndSet(new_contact, "Darkest secret: ", &Contact::setDarkestSecret);

	phone_book[_index % 8] = new_contact;
	_index++;
}

void PhoneBook::SearchContact()
{
	std::string			entry;
	int					index;

	if (not DisplayPhoneBook())
		return;

	while (true)
	{
		std::cout << "\e[35mIndex of the contact you're looking for: \e[0m";

		wrapGetline(entry);

		index = toInt(entry);
		if (index < 0)
		{
			std::cout << "\e[31;1m🈲 Error: You have to precise an index. Please try again 🈲\e[0m\n";
			continue;
		}
		else if (index > 7 or index >= _index)
		{
			std::cout << "\e[31;1m🈲 Error: Invalid index. Please try again 🈲\e[0m\n";
			continue;
		}
		else
			break;
	}

	std::cout << "\n\e[36;1mContact n°" << index << ":\e[0m\n";
	std::cout << "\e[36mFirst name - \e[0m" << phone_book[index].getFirstName() << '\n';
	std::cout << "\e[36mLast name - \e[0m" << phone_book[index].getLastName() << '\n';
	std::cout << "\e[36mNickname - \e[0m" << phone_book[index].getNickname() << '\n';
	std::cout << "\e[36mPhone number - \e[0m" << phone_book[index].getPhoneNumber() << '\n';
	std::cout << "\e[36mDarkest secret - \e[0m" << phone_book[index].getDarkestSecret() << "\n\n";
}
