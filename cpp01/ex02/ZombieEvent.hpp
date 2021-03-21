#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include "Zombie.hpp"

class ZombieEvent{
private:
	std::string type;
	std::string names[4];
public:
	ZombieEvent();
	~ZombieEvent();
	void setZombieType(std::string _type);
	Zombie *newZombie(std::string name);
	Zombie *randomChump();
};

#endif
