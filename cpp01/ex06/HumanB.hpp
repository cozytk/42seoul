//
// Created by Taekyun Kim on 3/21/21.
//

#ifndef CPP_HUMANB_HPP
#define CPP_HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon *weapon;
public:
	HumanB(std::string _name);
	void attack();
	void setWeapon(Weapon& _weapon);
};


#endif //CPP_HUMANB_HPP
