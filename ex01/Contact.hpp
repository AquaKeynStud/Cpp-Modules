#ifndef CONTACT_H
# define CONTACT_H

/* -- Includes -- */
#include <string>

/* -- Classes -- */
class	Contact
{
private:
	std::string	_nickname;
	std::string	_last_name;
	std::string	_first_name;
	std::string	_phone_number;
	std::string	_darkest_secret;

public:
	Contact();
	~Contact();

	// Getters //
	const std::string&	getNickname() const;
	const std::string&	getLastName() const;
	const std::string&	getFirstName() const;
	const std::string&	getPhoneNumber() const;
	const std::string&	getDarkestSecret() const;

	// Setters //
	void	setNickname(const std::string& nickname);
	void	setLastName(const std::string& last_name);
	void	setFirstName(const std::string& first_name);
	void	setPhoneNumber(const std::string& phone_number);
	void	setDarkestSecret(const std::string& darkest_secret);
};

#endif