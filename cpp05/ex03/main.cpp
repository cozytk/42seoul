#include "main.hpp"

int	main(void)
{
	Bureaucrat	taekkim("taekkim", 1);
	Intern		intern;
	Form		*form;

	form = intern.makeForm("shrubbery creation", "gam");
	taekkim.signForm(*form);
	taekkim.executeForm(*form);
	form = intern.makeForm("robotomy request", "gon");
	taekkim.signForm(*form);
	taekkim.executeForm(*form);
	form = intern.makeForm("presidential pardon", "gun");
	taekkim.signForm(*form);
	taekkim.executeForm(*form);
	form = intern.makeForm("invaild form", "lee");
	return (0);
}