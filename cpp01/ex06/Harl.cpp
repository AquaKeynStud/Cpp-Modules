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
	int lvl = (level == "DEBUG") ? 0 : (level == "INFO") ? 1 : (level == "WARNING") ? 2 : (level == "ERROR") ? 3 : -1;
	
	switch (lvl)
	{
		case 0:
			debug();
			/* fall through */
		case 1:
			info();
			/* fall through */
		case 2:
			warning();
			/* fall through */
		case 3:
			error();
			break;
		default:
			std::cout << "\e[1m☠️ [ Probably complaining about insignificant problems ] ☠️" << RESET;
	}
}
