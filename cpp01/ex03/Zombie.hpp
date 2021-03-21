#ifndef CPP_ZOMBIE_HPP
#define CPP_ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie{
private:
	std::string name;
	std::string type;
public:
	Zombie();
	~Zombie();
	void setZombie(std::string _name, std::string _type);
	void announce();
	void deleteMemory();
};

#endif
