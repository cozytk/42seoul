#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{
	names[0] = "GUN";
	names[1] = "GON";
	names[2] = "GAM";
	names[3] = "LEE";
}

ZombieEvent::~ZombieEvent()
{
}

void ZombieEvent::setZombieType(std::string _type)
{
	type = _type;
}

Zombie* ZombieEvent::newZombie(std::string _name)
{
	Zombie *one;

	one = new Zombie(_name, type);
	std::cout << "memory allocated dynamically" << std::endl;
	std::cout << "newZombie() generate new Zombie\n";
	return (one);
}

Zombie* ZombieEvent::randomChump()
{
	Zombie *one;

	std::srand(std::time(0));
	one = new Zombie(names[std::rand() % 4], type);
	std::cout << "memory allocated dynamically" << std::endl;
	std::cout << "randomChump() generate new Zombie\n";
	one->announce();
	return (one);
}
