#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() : name("Untilted") {}
Zombie::Zombie( std::string const &name ) : name(name) {}

Zombie::~Zombie() { std::cout << name << " has been destroyed.\n"; }

void Zombie::announce( void ) { std::cout << name << ":  BraiiiiiiinnnzzzZ...\n"; }
