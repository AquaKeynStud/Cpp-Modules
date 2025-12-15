#ifndef BRAIN_HPP
# define BRAIN_HPP

/* -- Includes -- */
#include <string>

/* -- Colors -- */
#define CREAT	"\e[38;2;220;150;230;1m"
#define DESTROY	"\e[38;2;180;130;255;1m"

/* -- Class -- */
class Brain
{
private:
	std::string	_ideas[100];

public:
// Constructors //
	Brain();
	Brain( const Brain& toCopy );

// Destructor //
	~Brain();

// Assignment operator //
	Brain& operator=( const Brain& other );

// Getters / Setters //
	const std::string&	getIdea( int index ) const;
	void				setIdea( int index, const std::string& idea );
};

#endif