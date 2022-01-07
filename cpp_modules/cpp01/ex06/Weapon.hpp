#ifndef CPP_WEAPON_HPP
#define CPP_WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
private:
	std::string type;
public:
	Weapon(std::string _type);
	~Weapon();
	const std::string& getType() const;
	void setType(std::string _type);
};


#endif //CPP_WEAPON_HPP
