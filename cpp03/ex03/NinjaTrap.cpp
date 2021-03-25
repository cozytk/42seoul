#include "NinjaTrap.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

/* static variable code */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

NinjaTrap::NinjaTrap()
{
	name = "NEW";
	hp = 60;
	maxHp = 60;
	ep = 120;
	maxEp = 120;
	lv = 1;
	MAD = 60;
	RAD = 5;
	arm = 0;
	type = "NIJ4-TP";
	std::cout << "NIJ4-TP, NEW player created\n";
}

NinjaTrap::NinjaTrap(std::string _name)
: ClapTrap(_name)
{
	name = _name;
	hp = 60;
	maxHp = 60;
	ep = 120;
	maxEp = 120;
	lv = 1;
	MAD = 60;
	RAD = 5;
	arm = 0;
	type = "NIJ4-TP";
	std::cout << "NIJ4-TP, player " << name << " created\n";
}

NinjaTrap::NinjaTrap(const NinjaTrap& copy)
: ClapTrap(copy)
{
	std::cout << "NIJ4-TP, player " << name << " created by copy\n";
}

/* ************************************************************************** */
/* ------------------------------- DESTRUCTOR ------------------------------- */
/* ************************************************************************** */

NinjaTrap::~NinjaTrap()
{
	std::cout << "NIJ4-TP, player " << name << " deleted\n";
}

/* ************************************************************************** */
/* -------------------------------- OVERLOAD -------------------------------- */
/* ************************************************************************** */

NinjaTrap& NinjaTrap::operator=(const NinjaTrap& obj)
{
	if (this == &obj)
		return (*this);
	this->ClapTrap::operator=(obj);
	std::cout << "NIJ4-TP, player " << name << " allocated\n";
	return (*this);
}

/* ************************************************************************** */
/* --------------------------------- GETTER --------------------------------- */
/* ************************************************************************** */

/* getter code */

/* ************************************************************************** */
/* --------------------------------- SETTER --------------------------------- */
/* ************************************************************************** */

/* setter code */

/* ************************************************************************** */
/* ------------------------------- EXCEPTION -------------------------------- */
/* ************************************************************************** */

/* exception code */

/* ************************************************************************** */
/* ---------------------------- MEMBER FUNCTION ----------------------------- */
/* ************************************************************************** */

void   NinjaTrap::ninjaShoebox(FragTrap const & target) const
{
	std::cout << type << " to " << target.getType() << ' ' << name << " attack " << target.getName() << std::endl;
}

void   NinjaTrap::ninjaShoebox(ScavTrap const & target) const
{
	std::cout << type << " to " << target.getType() << ' ' << name << " attack " << target.getName() << std::endl;
}

void   NinjaTrap::ninjaShoebox(NinjaTrap const & target) const
{
	std::cout << type << " to " << target.getType() << ' ' << name << " attack " << target.getName() << std::endl;
}

void   NinjaTrap::ninjaShoebox(ClapTrap const & target) const
{
	std::cout << type << " to " << target.getType() << ' ' << name << " attack " << target.getName() << std::endl;
}
