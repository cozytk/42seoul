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
	name = "NEW";
	hp = 100;
	maxHp = 100;
	ep = 50;
	maxEp = 50;
	lv = 1;
	MAD = 20;
	RAD = 15;
	arm = 3;
	type = "SC4V-TP";
	std::cout << "SC4V, NEW player created\n";
}

ScavTrap::ScavTrap(std::string _name)
: ClapTrap(_name)
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
	type = "SC4V-TP";
	std::cout << "SC4V, player " << name << " created\n";
}

ScavTrap::ScavTrap(const ScavTrap& copy)
: ClapTrap(copy)
{
	std::cout << "SC4V, player " << name << " created by copy\n";
}

/* ************************************************************************** */
/* ------------------------------- DESTRUCTOR ------------------------------- */
/* ************************************************************************** */

ScavTrap::~ScavTrap()
{
	std::cout << "SC4V, player " << name << " deleted\n";
}

/* ************************************************************************** */
/* -------------------------------- OVERLOAD -------------------------------- */
/* ************************************************************************** */

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	if (this == &obj)
		return (*this);
	this->ClapTrap::operator=(obj);
	std::cout << "SC4V, player " << name << " allocated\n";
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

void ScavTrap::challengeNewcomer()
{
	std::string challenges[5] = {"Use weak hand", "Close your eyes", "Use foot", "No sounds", "No challenge"};
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 4);

	std::cout << "Challenge! " << name << ", " << challenges[dis(gen)] << ".\n";
}
