#include "main.hpp"

int	main(void)
{
	Bureaucrat				gon("Gon", 1);
	ShrubberryCreationForm	gam("Gam");
	RobotomyRequestForm		gun("Gun");
	PresidentialPardonForm	lee("Lee");

	gon.executeForm(gam);

	gon.signForm(gam);
	gon.executeForm(gam);

	Bureaucrat				gon2("Gon2", 66);

	gon2.signForm(gun);
	gon2.executeForm(gun);
	gon.signForm(gun);
	gon.executeForm(gun);

	gon.signForm(lee);
	gon.executeForm(lee);

	return (0);
}