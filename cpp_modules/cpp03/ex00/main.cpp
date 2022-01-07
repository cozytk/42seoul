#include "FragTrap.hpp"

int		main(void)
{
	FragTrap Gon("gon");
	FragTrap Gam("gam");

	Gon.takeDamage(Gam.meleeAttack(Gon.getName()));
	Gon.takeDamage(Gam.rangedAttack(Gon.getName()));

	Gon.beRepaired(10);
	Gon.beRepaired(50);

	while (Gon.takeDamage(Gam.vaulthunter_dot_exe(Gon.getName())))
		;
	return (0);
}