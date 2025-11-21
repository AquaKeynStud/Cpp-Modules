#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() : name("Untilted") {}
Zombie::Zombie( const std::string& name ) : name(name) {}

Zombie::~Zombie() { std::cout << name << " has been destroyed.\n"; }

void Zombie::announce( void ) { std::cout << name << ":  BraiiiiiiinnnzzzZ...\n"; }

void Zombie::setName( const std::string& name ) { this->name = name; }
