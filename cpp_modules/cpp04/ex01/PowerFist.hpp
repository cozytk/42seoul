#ifndef POWER_FIST_HPP
# define POWER_FIST_HPP

# include <string>
# include <iostream>

# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
	private:
		/* declare member variable */
	public:
		PowerFist();
		PowerFist(const PowerFist& copy);
		PowerFist& operator=(const PowerFist& obj);
		virtual ~PowerFist();

		virtual void attack() const;
};

#endif
