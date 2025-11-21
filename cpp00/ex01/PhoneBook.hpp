#ifndef PHONEBOOK_H
# define PHONEBOOK_H

/* -- Includes -- */
#include "utils.hpp"
#include "Contact.hpp"

/* -- Classes -- */
class	PhoneBook
{
private:
	int		_index;
	Contact phone_book[8];
	void	AskAndSet(	Contact &contact,
						const std::string &prompt,
						void (Contact::*setter)(const std::string &)
					);

	bool	DisplayPhoneBook();

public:
	PhoneBook();
	~PhoneBook();

	// Setters //
	void	AddContact();

	void	SearchContact();
};

#endif