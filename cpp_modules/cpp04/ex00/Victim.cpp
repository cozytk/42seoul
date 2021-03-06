#include "main.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

/* static variable code */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

Victim::Victim()
{
}
Victim::Victim(std::string _name)
: name(_name)
{
	std::cout << "Some random victim called " << name << " just appeared!\n";
}

Victim::Victim(const Victim& copy)
: name(copy.name)
{
	std::cout << "Some random victim called " << name << " just appeared!\n";
}

/* ************************************************************************** */
/* ------------------------------- DESTRUCTOR ------------------------------- */
/* ************************************************************************** */

Victim::~Victim()
{
	std::cout << "Victim " << name << " just died for no apparent reason!\n";
}

/* ************************************************************************** */
/* -------------------------------- OVERLOAD -------------------------------- */
/* ************************************************************************** */

Victim& Victim::operator=(const Victim& obj)
{
	if (this == &obj)
		return (*this);
	name = obj.name;
	return (*this);
}

std::ostream&
operator<<(std::ostream& out, const Victim& victim)
{
	out << "I'm " << victim.getName() << " and I like otters!\n";
	return (out);
}

/* ************************************************************************** */
/* --------------------------------- GETTER --------------------------------- */
/* ************************************************************************** */

std::string Victim::getName() const
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

void Victim::getPolymorphed() const
{
	std::cout << name << " has been turned into a cute little sheep!\n";
}