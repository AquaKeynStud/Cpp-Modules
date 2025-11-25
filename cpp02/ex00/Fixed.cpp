#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0) { std::cout << "Default constructor called\n"; }

Fixed::~Fixed() { std::cout << "Destructor called\n"; }

Fixed::Fixed( const Fixed& other )
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed &Fixed::operator=( const Fixed& other )
{
	std::cout << "Copy assignement operator called\n";

	if (this != &other)
		_fixed = other.getRawBits();

	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (_fixed);
}

void Fixed::setRawBits( int const raw ) { _fixed = raw; }
