#ifndef BASE_HPP
# define BASE_HPP

/* -- Class -- */
class	Base
{
public:
	virtual ~Base() {};
};

class	A : public Base {};
class	B : public Base {};
class	C : public Base {};

#endif