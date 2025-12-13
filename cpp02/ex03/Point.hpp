#ifndef POINT_HPP
# define POINT_HPP

/* -- Includes -- */
#include "Fixed.hpp"

/* -- Class -- */
class Point
{
private:
	const Fixed	_x;
	const Fixed	_y;

public:
// Constructors //
	Point();
	Point( const Point& other );
	Point( const float x, const float y);

// Destructor //
	~Point();

// Assignment operator //
	Point&		operator=( const Point& other );

// Getters //
	const Fixed	getX( void ) const;
	const Fixed	getY( void ) const;
};

#endif