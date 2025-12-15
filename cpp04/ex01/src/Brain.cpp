#include <iostream>
#include "Brain.hpp"

/* -- Constructors -- */
Brain::Brain() { std::cout << CREAT << "🤓 Brain created !! 🤓\e[0m\n"; }

Brain::Brain(const Brain& toCopy)
{
	*this = toCopy;

	std::cout << CREAT << "🥸 Brain copied !! 🥸\e[0m\n";
}

/* -- Destructor -- */
Brain::~Brain() { std::cout << DESTROY << "🤯 Brain destroyed 🤯\e[0m\n"; }

/* -- Assignment operator -- */
Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
		for (int i = 0; i < 100; i++)
			_ideas[i] = other.getIdea(i);

	return (*this);
}

/* -- Getters / Setters -- */
const std::string& Brain::getIdea(int index) const
{
	static const std::string& error = "";
	if (index < 0 or index > 99)
	{
		std::cout << "\e[31;1m[Brain: getIdea] 🏯Error: List index out of range\e[0m\n";
		return (error);
	}

	return (_ideas[index]);
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index < 0 or index > 99)
	{
		std::cout << "\e[31;1m[Brain: setIdea] 🏯Error: List index out of range\e[0m\n";
		return ;
	}

	_ideas[index] = idea;
}
