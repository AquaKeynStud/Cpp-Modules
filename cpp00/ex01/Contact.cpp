#include "Contact.hpp"

Contact::Contact()
	: _nickname("N/A"),
	_last_name("N/A"),
	_first_name("N/A"),
	_phone_number("N/A"),
	_darkest_secret("N/A")
{}

Contact::~Contact() {}

/* -- Getters -- */
const std::string& Contact::getNickname() const { return (_nickname); }
const std::string& Contact::getLastName() const { return (_last_name); }
const std::string& Contact::getFirstName() const { return (_first_name); }
const std::string& Contact::getPhoneNumber() const { return (_phone_number); }
const std::string& Contact::getDarkestSecret() const { return (_darkest_secret); }

/* -- Setters -- */
void Contact::setNickname(const std::string& nickname){ _nickname = nickname; }
void Contact::setLastName(const std::string& last_name) { _last_name = last_name; }
void Contact::setFirstName(const std::string& first_name) { _first_name = first_name; }
void Contact::setPhoneNumber(const std::string& phone_number) { _phone_number = phone_number; }
void Contact::setDarkestSecret(const std::string& darkest_secret) { _darkest_secret = darkest_secret; }
