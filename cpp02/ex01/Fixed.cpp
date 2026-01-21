#include <cmath>
#include <iostream>
#include "Fixed.hpp"

/* -- Ex00 Functions -- */

Fixed::Fixed() : _fixed(0) { std::cout << "Default constructor called\n"; }

Fixed::~Fixed() { std::cout << "Destructor called\n"; }

Fixed::Fixed( const Fixed& other ) : _fixed(other.getRawBits())
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

int Fixed::getRawBits( void ) const { return (_fixed); }

void Fixed::setRawBits( int const raw ) { _fixed = raw; }

/* -- Ex01 functions here -- */

Fixed::Fixed( const int fixed ) : _fixed(fixed << _fractionnal)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed( const float fixed ) : _fixed(roundf(fixed * (1 << _fractionnal)))
{
	std::cout << "Float constructor called\n";
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(_fixed) / (1 << _fractionnal));
}

int Fixed::toInt( void ) const { return (_fixed >> _fractionnal); }

std::ostream& operator<<( std::ostream& os, const Fixed& fixed )
{
	os << fixed.toFloat();
	return (os);
}
