#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
	private:
		std::string name;
		int ap;
		AWeapon *weapon;
	public:
		Character();
		Character(std::string const & name);
		Character(const Character& copy);
		~Character();
		Character& operator=(const Character& obj);
		void recoverAP();
		void equip(AWeapon *_weapon);
		void attack(Enemy *_enemy);
		std::string const getName() const;
		AWeapon* getWeapon() const;
		int getAp() const;
};
std::ostream&   operator<<(std::ostream& out, const Character& character);

#endif
