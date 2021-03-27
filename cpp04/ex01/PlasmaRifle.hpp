#ifndef PLASMA_RIFLE_HPP
# define PLASMA_RIFLE_HPP

# include <string>
# include <iostream>

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
	public:
		PlasmaRifle();
		PlasmaRifle(const PlasmaRifle& copy);
		PlasmaRifle& operator=(const PlasmaRifle& obj);
		virtual ~PlasmaRifle();

		virtual void attack() const;
};

/* global operator overload */
#endif
