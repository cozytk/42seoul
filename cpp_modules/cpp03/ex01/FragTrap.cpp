#include "FragTrap.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

/* static variable code */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

FragTrap::FragTrap()
{
	name = "NONE";
	hp = 100;
	maxHp = 100;
	ep = 100;
	maxEp = 100;
	lv = 1;
	MAD = 30;
	RAD = 20;
	arm = 5;
	std::cout << "Create FragTrap Player " << name << '!' << std::endl;
}
FragTrap::FragTrap(std::string _name)
{
	name = _name;
	hp = 100;
	maxHp = 100;
	ep = 100;
	maxEp = 100;
	lv = 1;
	MAD = 30;
	RAD = 20;
	arm = 5;
	std::cout << "Create FragTrap Player " << name << '!' << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy)
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
	std::cout << "Create FragTrap Player " << name << '!' << std::endl;
}

/* ************************************************************************** */
/* ------------------------------- DESTRUCTOR ------------------------------- */
/* ************************************************************************** */

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " GAME OVER\n";
}

/* ************************************************************************** */
/* -------------------------------- OVERLOAD -------------------------------- */
/* ************************************************************************** */

FragTrap& FragTrap::operator=(const FragTrap& obj)
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

std::string FragTrap::getName()
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


unsigned int FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << name << " attacks " << \
	target << " at range, causing " << RAD << " points of damage!\n";
	return (RAD);
}

unsigned int FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << name << " attacks " << \
	target << " at melee, causing " << MAD << " points of damage!\n";
	return (MAD);
}

unsigned int FragTrap::takeDamage(unsigned int amount)
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

unsigned int FragTrap::beRepaired(unsigned int amount)
{
	std::cout << name << " repaired " << amount << std::endl;
	hp += amount;
	if (hp > maxHp)
		hp = maxHp;
	std::cout << name << " hp is " << hp << std::endl;
	return (hp);
}

unsigned int FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string	attack[5] = {"pinch", "punch", "slap", "kick", "shot"};
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 4);
	int	damage[5] = {3, 10, 15, 20, 50};
	int	i;

	if (ep < 25)
	{
		std::cout << "Not enough energy.\n";
		return (0);
	}
	ep -= 25;
	i = dis(gen);
	std::cout << name << " funny attacks " << target << " with " << attack[i] \
			 << " causing " << damage[i] << " points of damage!\n";
	return (damage[i]);
}