#ifndef FIXED_HPP
# define FIXED_HPP

/* -- Class -- */
class Fixed
{
private:
	int					_fixed;
	static const int	_fractionnal = 8;

public:
// Constructors //
	Fixed();
	Fixed( const int fixed );
	Fixed( const float fixed );
	Fixed( const Fixed& other );

// Destructor //
	~Fixed();

// Arithmetic operators //
	Fixed	operator+( const Fixed& other );	// <- new
	Fixed	operator-( const Fixed& other );	// <- new
	Fixed	operator*( const Fixed& other );	// <- new
	Fixed	operator/( const Fixed& other );	// <- new

// Increment/Decrement operators //
	Fixed	operator++( int );		// <- new
	Fixed	operator--( int );		// <- new
	Fixed&	operator++( void );		// <- new
	Fixed&	operator--( void );		// <- new
	
// Comparison operators //
	bool	operator<( const Fixed& other ) const;	// <- new
	bool	operator>( const Fixed& other ) const;	// <- new
	bool	operator<=( const Fixed& other ) const;	// <- new
	bool	operator>=( const Fixed& other ) const;	// <- new
	bool	operator==( const Fixed& other ) const;	// <- new
	bool	operator!=( const Fixed& other ) const;	// <- new

// Min/Max operators //
	static Fixed&		min( Fixed& a, Fixed& b );
	static Fixed&		max( Fixed& a, Fixed& b );
	static const Fixed&	min( const Fixed& a, const Fixed& b );
	static const Fixed&	max( const Fixed& a, const Fixed& b );

// Assignment operator //
	Fixed&	operator=( const Fixed& other );

// Getters //
	int		getRawBits( void ) const;

// Setters //
	void	setRawBits( int const raw );

// Methods //
	int		toInt( void ) const;
	float	toFloat( void ) const;

};

std::ostream& operator<<( std::ostream& os, const Fixed& fixed );

#endif