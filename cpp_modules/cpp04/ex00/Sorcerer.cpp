#include "main.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

/* static variable code */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

Sorcerer::Sorcerer()
{
	/* no param constructor should not be initialized*/
}
Sorcerer::Sorcerer(const std::string _name, const std::string _title)
: name(_name), title(_title)
{
	std::cout << name << ", " << title << ", is born!\n";
}

Sorcerer::Sorcerer(const Sorcerer& copy)
: name(copy.name), title(copy.title)
{
	std::cout << name << ", " << title << ", is born!\n";
}

/* ************************************************************************** */
/* ------------------------------- DESTRUCTOR ------------------------------- */
/* ************************************************************************** */

Sorcerer::~Sorcerer()
{
	std::cout << name << ", " << title << ", is dead. Consequences will never be the same!\n";
}

/* ************************************************************************** */
/* -------------------------------- OVERLOAD -------------------------------- */
/* ************************************************************************** */

Sorcerer& Sorcerer::operator=(const Sorcerer& obj)
{
	if (this == &obj)
		return (*this);
	name = obj.name;
	title = obj.title;
	return (*this);
}

std::ostream&
operator<<(std::ostream& out, const Sorcerer& sorcerer)
{
	out << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies!\n";
	return (out);
}

/* ************************************************************************** */
/* --------------------------------- GETTER --------------------------------- */
/* ************************************************************************** */

std::string Sorcerer::getName() const
{
	return (name);
}

std::string Sorcerer::getTitle() const
{
	return (title);
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

void Sorcerer::polymorph(Victim const & victim) const
{
	victim.getPolymorphed();
}