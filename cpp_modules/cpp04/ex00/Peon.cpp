#include "Peon.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

/* static variable code */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

Peon::Peon() {}
Peon::Peon(std::string _name)
: Victim(_name)
{
	std::cout << "Zog zog.\n";
}

Peon::Peon(const Peon& copy)
: Victim(copy)
{
	std::cout << "Zog zog.\n";
}

/* ************************************************************************** */
/* ------------------------------- DESTRUCTOR ------------------------------- */
/* ************************************************************************** */

Peon::~Peon()
{
	std::cout << "Bleuark...\n";
}

/* ************************************************************************** */
/* -------------------------------- OVERLOAD -------------------------------- */
/* ************************************************************************** */

Peon& Peon::operator=(const Peon& obj)
{
	if (this == &obj)
		return (*this);
	this->Victim::operator=(obj);
	return (*this);
}

std::ostream&
operator<<(std::ostream& out, const Peon& peon)
{
	out << "I'm " << peon.getName() << " and I like otters!\n";
	return (out);
}

/* ************************************************************************** */
/* --------------------------------- GETTER --------------------------------- */
/* ************************************************************************** */

//std::string Peon::getName() const
//{
//	return (name);
//}

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

void Peon::getPolymorphed() const
{
	std::cout << name << " has been turned into a pink pony!\n";
}
