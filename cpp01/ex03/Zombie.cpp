#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "New Zombie generated()\n";
}

void Zombie::setZombie(std::string _name, std::string _type)
{
	name = _name;
	type = _type;
}

Zombie::~Zombie()
{
	std::cout << "Zombie destroyed\n";
}

void Zombie::announce()
{
	std::cout << '<' << name << " (" << type << ")> Braiiiiiiinnnssss...\n" ;
}
