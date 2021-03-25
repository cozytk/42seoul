#include "ClapTrap.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

/* static variable code */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

ClapTrap::ClapTrap()
{
	std::cout << "Create default info !" << std::endl;
}

ClapTrap::ClapTrap(std::string _name) : name(_name)
{
	std::cout << "Create " << name << "'s default info !" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	name = _name;
	hp = _hp;
	maxHp = _maxHp;
	ep = _ep;
	maxEp = _maxEp;
	lv = _lv;
	MAD = _MAD;
	RAD = _RAD;
	arm = _arm;
	type = _type;
	std::cout << "Create " << name << "'s default info by copy!" << std::endl;
}

/* ************************************************************************** */
/* ------------------------------- DESTRUCTOR ------------------------------- */
/* ************************************************************************** */

ClapTrap::~ClapTrap()
{
	std::cout << "Exit " << name << "'s default info!" << std::endl;
}

/* ************************************************************************** */
/* -------------------------------- OVERLOAD -------------------------------- */
/* ************************************************************************** */

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	if (this == &obj)
		return (*this);
	name = _name;
	hp = _hp;
	maxHp = _maxHp;
	ep = _ep;
	maxEp = _maxEp;
	lv = _lv;
	MAD = _MAD;
	RAD = _RAD;
	arm = _arm;
	type = _type;
	std::cout << "Overload " << name << "'s default info by assignment!" << std::endl;
	return (*this);
}

/* ************************************************************************** */
/* --------------------------------- GETTER --------------------------------- */
/* ************************************************************************** */

std::string ClapTrap::getName()
{
	return (name);
}

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
unsigned int ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << type << ' ' << name << " attacks " << \
	target << " at range, causing " << RAD << " points of damage!\n";
	return (RAD);
}

unsigned int ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << type << ' ' << name << " attacks " << \
	target << " at melee, causing " << MAD << " points of damage!\n";
	return (MAD);
}

unsigned int ClapTrap::takeDamage(unsigned int amount)
{
	if (amount == 0)
		return (0);
	if (amount < arm)
		amount = 0;
	else
		amount -= arm;
	std::cout << name << " has " << arm << " armor" << std::endl;
	if (hp <= amount)
	{
		std::cout << name << " is dead\n";
		return (0);
	}
	hp -= amount;
	std::cout << name << " hp is " << hp << std::endl;
	return (hp);
}

unsigned int ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << name << " repaired" << std::endl;
	hp += amount;
	if (hp > maxHp)
		hp = maxHp;
	std::cout << name << " hp is " << hp << std::endl;
	return (hp);
}