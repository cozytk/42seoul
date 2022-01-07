#include "Character.hpp"

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

Character::Character()
: name("unknown"), ap(40), weapon((AWeapon *)0)
{}


Character::Character(std::string const & name)
: name(name), ap(40), weapon((AWeapon *)0)
{
}
Character::Character(const Character& copy)
: name(copy.name), ap(copy.ap), weapon(copy.weapon)
{
}

/* ************************************************************************** */
/* ------------------------------- DESTRUCTOR ------------------------------- */
/* ************************************************************************** */

Character::~Character()
{
}

/* ************************************************************************** */
/* -------------------------------- OVERLOAD -------------------------------- */
/* ************************************************************************** */

Character& Character::operator=(const Character& obj)
{
	if (this == &obj)
		return (*this);
	name = obj.name;
	ap = obj.ap;
	weapon = obj.weapon;
	return (*this);
}

std::ostream&
operator<<(std::ostream& out, const Character& character)
{
	if (character.getWeapon())
	{
		out << character.getName() << " has " << character.getAp() <<
		    " AP and wields a " << character.getWeapon()->getName() << std::endl;
	}
	else
	{
		out << character.getName() << " has " << character.getAp() << " AP and is unarmed\n";
	}
	return (out);
}

/* ************************************************************************** */
/* --------------------------------- GETTER --------------------------------- */
/* ************************************************************************** */

std::string const Character::getName() const
{
	return (name);
}

AWeapon* Character::getWeapon() const
{
	return (weapon);
}

int Character::getAp() const
{
	return (ap);
}
/* ************************************************************************** */
/* --------------------------------- SETTER --------------------------------- */
/* ************************************************************************** */

void Character::equip(AWeapon *_weapon)
{
	weapon = _weapon;
}

/* ************************************************************************** */
/* ------------------------------- EXCEPTION -------------------------------- */
/* ************************************************************************** */

/* exception code */

/* ************************************************************************** */
/* ---------------------------- MEMBER FUNCTION ----------------------------- */
/* ************************************************************************** */

void Character::recoverAP()
{
	ap += 10;
	if (ap > 40)
		ap = 40;
}


void Character::attack(Enemy *_enemy)
{
	if (weapon == (AWeapon *)0 || !_enemy)
		return ;
	if (ap < weapon->getAPCost())
	{
		std::cout << "Not enough apcost\n";
		return ;
	}
	ap -= weapon->getAPCost();
	std::cout << name << " attacks " << _enemy->getType() << " with a " << weapon->getName() << "\n";
	weapon->attack();
	_enemy->takeDamage(weapon->getDamage());
	if (_enemy->getHP() <= 0)
		delete _enemy;
p