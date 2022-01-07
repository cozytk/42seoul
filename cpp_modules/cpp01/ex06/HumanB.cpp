#include "HumanB.hpp"

HumanB::HumanB(std::string _name) : name(_name)
{
}

void HumanB::setWeapon(Weapon &_weapon)
{
	weapon = &_weapon;
}

void HumanB::attack()
{
	std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}
