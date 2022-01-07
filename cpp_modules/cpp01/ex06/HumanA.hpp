//
// Created by Taekyun Kim on 3/21/21.
//

#ifndef CPP_HUMANA_HPP
#define CPP_HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon& weapon;
public:
	HumanA(std::string _name, Weapon& _weapon);
	void attack();
};


#endif //CPP_HUMANA_HPP
