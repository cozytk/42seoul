#include "MateriaSource.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

/* static variable code */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

MateriaSource::MateriaSource()
: num(0)
{
	for (int i = 0; i < 4; i++)
		sources[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
: num(0)
{
	for (int i = 0; i < num; i++)
		learnMateria(copy.sources[i]->clone());
	for (int i = num; i < 4; i++)
		sources[i] = 0;
}

/* ************************************************************************** */
/* ------------------------------- DESTRUCTOR ------------------------------- */
/* ************************************************************************** */

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (sources[i])
			delete sources[i];
	}
}

/* ************************************************************************** */
/* -------------------------------- OVERLOAD -------------------------------- */
/* ************************************************************************** */

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	if (this == &obj)
		return (*this);
	for (int i = 0; i < num; i++)
	{
		if (sources[i])
			delete sources[i];
	}
	for (int i = 0; i < obj.num; i++)
		learnMateria(obj.sources[i]->clone());
	return (*this);
}

void
MateriaSource::learnMateria(AMateria *m)
{
	if (num > 3 || !m)
		return ;
	sources[num] = m->clone();
	num++;
}

AMateria*
MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < num; i++)
	{
		if (sources[i]->getType() == type)
			return (this->sources[i]->clone());
	}
	return (0);
}
