#include "Pony.hpp"

Pony::Pony(std::string _name, int _age)
{
	name = _name;
	age = _age;
	std::cout << name << " init\n";
}

Pony::~Pony()
{
	std::cout << "No exist anymore\n";
}

void Pony::print()
{
	std::cout << "name is " << name << std::endl;
	std::cout << "age is " << age << std::endl;
}

