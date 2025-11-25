#include <cmath>
#include <limits>
#include <iostream>
#include "Fixed.hpp"

/* -- Ex00 Functions -- */

Fixed::Fixed() : _fixed(0) {}

Fixed::~Fixed() {}

Fixed::Fixed( const Fixed& other ) : _fixed(other.getRawBits()) {}

Fixed &Fixed::operator=( const Fixed& other )
{
	if (this != &other)
		_fixed = other.getRawBits();
	
	return (*this);
}

int Fixed::getRawBits( void ) const { return (_fixed); }

void Fixed::setRawBits( int const raw ) { _fixed = raw; }

/* -- Ex01 functions -- */

Fixed::Fixed( const int fixed ) : _fixed(fixed << _fractionnal) {}

Fixed::Fixed( const float fixed ) : _fixed(roundf(fixed * (1 << _fractionnal))) {}

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

/* -- Ex02 Functions here -- */

bool Fixed::operator<( const Fixed& other ) const
{
	return (_fixed < other.getRawBits());
}

bool Fixed::operator>( const Fixed& other ) const
{
	return (_fixed > other.getRawBits());
}

bool Fixed::operator<=( const Fixed& other ) const
{
	return (_fixed <= other.getRawBits());
}

bool Fixed::operator>=( const Fixed& other ) const
{
	return (_fixed >= other.getRawBits());
}

bool Fixed::operator==( const Fixed& other ) const
{
	return (_fixed == other.getRawBits());
}

bool Fixed::operator!=( const Fixed& other ) const
{
	return (_fixed != other.getRawBits());
}

Fixed Fixed::operator+( const Fixed& other )
{
	Fixed	res;

	res.setRawBits( _fixed + other.getRawBits() );
	return (res); 
}

Fixed	Fixed::operator++( int )
{
	Fixed	tmp;
	tmp = *this;
	_fixed++;

	return (tmp);
}

Fixed	Fixed::operator--( int )
{
	Fixed	tmp;
	tmp = *this;
	_fixed--;

	return (tmp);
}

Fixed&	Fixed::operator++( void )
{
	_fixed++;
	return (*this);
}

Fixed&	Fixed::operator--( void )
{
	_fixed--;
	return (*this);
}

Fixed Fixed::operator-( const Fixed& other )
{
	Fixed	res;

	res.setRawBits( _fixed - other.getRawBits() );
	return (res); 
}

Fixed Fixed::operator*( const Fixed& other )
{
	Fixed	res;

	res.setRawBits( (_fixed * other.getRawBits()) >> _fractionnal );
	return (res);
}

Fixed Fixed::operator/( const Fixed& other )
{
	Fixed	res;

	if (not other.getRawBits())
	{
		std::cout << "\e[31;1m🈲 Error: Division by 0 🈲\e[0m" << std::endl;
		res.setRawBits( std::numeric_limits<int>::max() );
	}
	else
		res.setRawBits( (_fixed << _fractionnal) / other.getRawBits() );
	return (res);
}

Fixed&	Fixed::min( Fixed& a, Fixed& b ) { return (a < b ? a : b); }

Fixed&	Fixed::max( Fixed& a, Fixed& b ) { return (a > b ? a : b); }

const Fixed&	Fixed::min( const Fixed& a, const Fixed& b ) { return (a < b ? a : b); }

const Fixed&	Fixed::max( const Fixed& a, const Fixed& b ) { return (a > b ? a : b); }
