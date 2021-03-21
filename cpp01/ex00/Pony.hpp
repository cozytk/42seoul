#ifndef PONY_HPP
#define PONY_HPP

#include <iostream>
#include <string>

class Pony
{
private:
	std::string name;
	int age;
public:
	Pony(std::string _name, int _age);
	~Pony();
	void print();
};

#endif
