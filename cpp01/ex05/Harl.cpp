#include <iostream>
#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug( void )
{
	std::cout << DEBUG << "[🫧 DEBUG 🫧]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
	std::cout << RESET;
}

void Harl::info( void )
{
	std::cout << INFO << "[🗺️ INFO 🗺️]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
	std::cout << RESET;
}

void Harl::warning( void )
{
	std::cout << WARNING << "[🚧 WARNING 🚧]\n";
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.\n";
	std::cout << RESET;
}

void Harl::error( void )
{
	std::cout << ERROR << "[🏯 ERROR 🏯]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
	std::cout << RESET;
}

void Harl::complain( std::string level )
{
	std::string	levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void		(Harl::* const f[4])( void ) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*f[i])();
			return;
		}
	}

	std::cout << "\e[1m☠️ [ Probably complaining about insignificant problems ] ☠️" << RESET;
}
