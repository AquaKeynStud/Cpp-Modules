#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

/* -- Includes -- */
#include <string>
#include <stdint.h>

/* -- Struct -- */
struct	Data
{
	std::string text;
};


/* -- Class -- */
class	Serializer
{
private:
	Serializer();
	Serializer(const Serializer& toCopy);
	~Serializer();
	Serializer& operator=(const Serializer& other);

public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif
