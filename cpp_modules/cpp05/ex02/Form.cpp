#include "Form.hpp"

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

Form::Form()
: _name(0), _signed(0), _signGrade(0), _execGrade(0)
{}
Form::Form(const std::string & name, const int signGrade, const int execGrade)
: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw Form::GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& copy)
: _name(copy.getName()), _signed(copy._signed), _signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade())
,_target(copy.getTarget())
{
}

/* ************************************************************************** */
/* ------------------------------- DESTRUCTOR ------------------------------- */
/* ************************************************************************** */

Form::~Form()
{
}

/* ************************************************************************** */
/* -------------------------------- OVERLOAD -------------------------------- */
/* ************************************************************************** */

Form& Form::operator=(const Form& obj)
{
	if (this == &obj)
		return (*this);
	_signed = obj.getSigned();
	return (*this);
}

std::ostream&
operator<<(std::ostream& out, const Form& form)
{
	out << "Form state : " << form.getName();
	if (form.getSigned())
		out << " signed.";
	else
		out << " not signed.";
	out << "\ngrade require to sign is " << form.getSignGrade() <<
	"\ngrade require to exec is " << form.getExecGrade() << ".";
	return (out);
}

/* ************************************************************************** */
/* --------------------------------- GETTER --------------------------------- */
/* ************************************************************************** */

std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getSignGrade() const
{
	return (_signGrade);
}

int Form::getExecGrade() const
{
	return (_execGrade);
}

std::string Form::getTarget() const
{
	return (_target);
}
/* ************************************************************************** */
/* --------------------------------- SETTER --------------------------------- */
/* ************************************************************************** */

void Form::setTarget(std::string target)
{
	_target = target;
}

/* ************************************************************************** */
/* ------------------------------- EXCEPTION -------------------------------- */
/* ************************************************************************** */

void Form::beSigned(Bureaucrat & obj)
{
	if (_signGrade >= obj.getGrade())
		_signed = true;
	else
		throw GradeTooLowException();
}

void Form::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > _execGrade)
		throw Form::GradeTooLowException();
	else if (!_signed)
		throw Form::FormNotSignedException();
	else
		action();
}

/* ************************************************************************** */
/* ---------------------------- MEMBER FUNCTION ----------------------------- */
/* ************************************************************************** */

