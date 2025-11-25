#ifndef FIXED_HPP
# define FIXED_HPP

/* -- Class -- */
class Fixed
{
private:
	int					_fixed;
	static const int	_fractionnal = 8;

public:
	Fixed();
	Fixed( const int fixed );	// <- new
	Fixed( const float fixed );	// <- new

	~Fixed();

	Fixed( const Fixed& other );

	Fixed& operator=(const Fixed& other);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;	// <- new
	int		toInt( void ) const;	// <- new

};

std::ostream& operator<<( std::ostream& os, const Fixed& fixed );

#endif