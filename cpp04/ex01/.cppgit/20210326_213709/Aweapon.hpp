#ifndef A_WEAPON_HPP
# define A_WEAPON_HPP

# include <string>
# include <iostream>

class AWeapon {
	private:
		std::string name;
		int         apcost;
		int         damage;
	public:
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(const AWeapon& copy);
		AWeapon& operator=(const AWeapon& obj);
		virtual ~AWeapon();
		std::string getName() const;
		int getAPCost() const;
		int getDamage() const;
		void attack() const = 0;
};

#endif
