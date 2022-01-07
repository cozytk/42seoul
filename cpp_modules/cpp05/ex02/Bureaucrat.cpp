#include "Bureaucrat.hpp"

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string &_name, int _grade)
: name(_name), grade(_grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
: name(copy.name), grade(copy.grade)
{
}

/* ************************************************************************** */
/* ------------------------------- DESTRUCTOR ------------------------------- */
/* ************************************************************************** */

Bureaucrat::~Bureaucrat()
{
}

/* ************************************************************************** */
/* -------------------------------- OVERLOAD -------------------------------- */
/* ************************************************************************** */

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this == &obj)
		return (*this);
	grade = obj.grade;
	return (*this);
}

std::ostream&
operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out);
}

/* ************************************************************************** */
/* --------------------------------- GETTER --------------------------------- */
/* ************************************************************************** */

std::string Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
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

void Bureaucrat::incGrade()
{
	std::cout << "increase grade\n";
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decGrade()
{
	std::cout << "decrease grade\n";
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(Form & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signs " << form.getName() << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << getName() << " cannot sign " << form.getName() << " because " << e.what() << "\n";
	}
}

void Bureaucrat::executeForm(Form & form)
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executes " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << getName() << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
	}
}
