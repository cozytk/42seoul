#include "span.hpp"

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

Span::Span() {}
Span::Span(unsigned int n)
: _n(n), _v(0)
{
	if (n)
		_v = new std::vector<int>[n];
}

Span::Span(const Span& copy)
: _n(copy._n), _v(copy._v)
{
	*this = copy;
}

/* ************************************************************************** */
/* ------------------------------- DESTRUCTOR ------------------------------- */
/* ************************************************************************** */

Span::~Span()
{
	if (_v)
		delete[] _v;
}

/* ************************************************************************** */
/* -------------------------------- OVERLOAD -------------------------------- */
/* ************************************************************************** */

Span& Span::operator=(const Span& obj)
{
	if (this == &obj)
		return (*this);
	_n = obj._n;
	_v = obj._v;
	return (*this);
}

/* ************************************************************************** */
/* --------------------------------- GETTER --------------------------------- */
/* ************************************************************************** */

std::vector<int>	Span::getVect(void) const
{
	return (*_v);
}


int                 Span::getSize() const
{
	return (_n);
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

void                Span::addNumber(int n)
{
	if (_v->size() >= _n)
		throw Span::NoSpaceException();
	_v->push_back(n);
}

void				Span::addNumbers(int begin, int end)
{
	if (begin > end)
		throw Span::NoSpaceException();
	for ( int i = begin ; i <= end ; i++ )
	{
		if (_v->size() >= _n)
			throw std::runtime_error("Container is full !");
		_v->push_back(i);
	}
}

unsigned int        Span::longestSpan()
{
	std::vector<int>	v = *_v;

	if (_v->size() < 2)
		throw NoSpanException();
	std::sort(v.begin(), v.end());
	return (*(v.end() - 1) - *v.begin());
}

unsigned int        Span::shortestSpan()
{
	std::vector<int>	v = *_v;
	int					ret = 2147483647;
	int					prev;

	if (_v->size() < 2)
		throw NoSpanException();
	std::sort(v.begin(), v.end());
	prev = *v.begin();
	for (std::vector<int>::iterator it = v.begin() + 1 ; it != v.end() ; it++)
	{
		if (ret > *it - prev)
			ret = *it - prev;
		prev = *it;
	}

	return (ret);
}

const char* Span::NoSpaceException::what() const throw()
{
	return ("No Space Exception.");
}

const char* Span::NoSpanException::what() const throw()
{
	return ("No Span Exception.");
}