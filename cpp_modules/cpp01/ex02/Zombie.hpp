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
	Zombie(std::string _name, std::string _type);
	~Zombie();
	void announce();
	void deleteMemory();
};

#endif //CPP_ZOMBIE_HPP
