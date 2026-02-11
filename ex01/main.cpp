#include <iostream>
#include "Serializer.hpp"

#define	BOLD	"\e[1m"
#define	RESET	"\e[0m\n"

int main()
{
	Data data;

	data.text = "Bonjour comment ça va ?";

	std::cout << BOLD "Adresse de data: " << &data << RESET;

	uintptr_t	raw = Serializer::serialize(&data);
	Data*		ptr = Serializer::deserialize(raw);

	std::cout << BOLD "Raw: " << raw << RESET;
	std::cout << BOLD "Ptr: "  << ptr << RESET;
	
	std::cout << ptr->text << RESET;

	return (0);
}