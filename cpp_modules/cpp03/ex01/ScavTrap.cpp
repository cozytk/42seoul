#include "ScavTrap.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

/* static variable code */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

ScavTrap::ScavTrap()
{
	name = "NONE";
	hp = 100;
	maxHp = 100;
	ep = 50;
	maxEp = 50;
	lv = 1;
	MAD = 20;
	RAD = 15;
	arm = 3;
	std::cout << "Create ScavTrap Player " << name << '!' << std::endl;
}

ScavTrap::ScavTrap(std::string _name)
{
	name = _name;
	hp = 100;
	maxHp = 100;
	ep = 50;
	maxEp = 50;
	lv = 1;
	MAD = 20;
	RAD = 15;
	arm = 3;
	std::cout << "Create ScavTrap Player " << name << '!' << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
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
	std::cout << "Create ScavTrap Player " << name << '!' << std::endl;
}

/* ************************************************************************** */
/* ------------------------------- DESTRUCTOR ------------------------------- */
/* ************************************************************************** */

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " GAME OVER\n";
}

/* ************************************************************************** */
/* -------------------------------- OVERLOAD -------------------------------- */
/* ************************************************************************** */

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
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
	return (*this);
}

/* ************************************************************************** */
/* --------------------------------- GETTER --------------------------------- */
/* ************************************************************************** */

std::string ScavTrap::getName()
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


unsigned int ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "SC4V-TP " << name << " attacks " << \
	target << " at range, causing " << RAD << " points of damage!\n";
	return (RAD);
}

unsigned int ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "SC4V-TP " << name << " attacks " << \
	target << " at melee, causing " << MAD << " points of damage!\n";
	return (MAD);
}

unsigned int ScavTrap::takeDamage(unsigned int amount)
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

unsigned int ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << name << " repaired " << amount << std::endl;
	hp += amount;
	if (hp > maxHp)
		hp = maxHp;
	std::cout << name << " hp is " << hp << std::endl;
	return (hp);
}

void ScavTrap::challengeNewcomer()
{
	std::string challenges[5] = {"Use weak hand", "Close your eyes", "Use foot", "No sounds", "No challenge"};
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 4);

	std::cout << "Challenge! " << name << ", " << challenges[dis(gen)] << ".\n";
}