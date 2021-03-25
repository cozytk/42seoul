#include "ClapTrap.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

/* static variable code */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

ClapTrap::ClapTrap() : type("CL4P-TP")
{
	name = "NEW";
	std::cout << "CL4P-TP, Create default info !" << std::endl;
}

ClapTrap::ClapTrap(std::string _name) : name(_name), type("CL4P-TP")
{
	std::cout << "CL4P-TP, Create " << name << "'s default info !" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	name = copy.name;
	hp = copy.hp;
	maxHp = copy.maxHp;
	ep = copy.ep;
	maxEp = copy.maxEp;
	lv = copy.lv;
	MAD = copy.MAD;
	RAD = copy.RAD;
	arm = copy.arm;
	type = copy.type;
	std::cout << "CL4P-TP, Create " << name << "'s default info by copy!" << std::endl;
}

/* ************************************************************************** */
/* ------------------------------- DESTRUCTOR ------------------------------- */
/* ************************************************************************** */

ClapTrap::~ClapTrap()
{
	std::cout << "CL4P-TP, Exit " << name << "'s default info!" << std::endl;
}

/* ************************************************************************** */
/* -------------------------------- OVERLOAD -------------------------------- */
/* ************************************************************************** */

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	if (this == &obj)
		return (*this);
	name = obj.name;
	hp = obj.hp;
	maxHp = obj.maxHp;
	ep = obj.ep;
	maxEp = obj.maxEp;
	lv = obj.lv;
	MAD = obj.MAD;
	RAD = obj.RAD;
	arm = obj.arm;
	type = obj.type;
	std::cout << "CL4P-TP, Overload " << name << "'s default info by assignment!" << std::endl;
	return (*this);
}

/* ************************************************************************** */
/* --------------------------------- GETTER --------------------------------- */
/* ************************************************************************** */

std::string ClapTrap::getName() const
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
	std::cout << type << ' ' << name << " has " << arm << " armor" << std::endl;
	if (hp <= amount)
	{
		std::cout << name << " is dead\n";
		return (0);
	}
	hp -= amount;
	std::cout << type << ' ' << name << " hp is " << hp << std::endl;
	return (hp);
}

unsigned int ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << type << ' ' << name << " repaired" << std::endl;
	hp += amount;
	if (hp > maxHp)
		hp = maxHp;
	std::cout << type << ' ' << name << " hp is " << hp << std::endl;
	return (hp);
}