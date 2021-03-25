#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <unistd.h>

int		main(void)
{
	FragTrap Gon("gon");
	FragTrap Gam("gam");
	ScavTrap Gun("gun");
	ScavTrap Lee("lee");

	std::cout << "-----------------------\n";
	Gon.takeDamage(Gam.meleeAttack(Gon.getName()));
	Gon.takeDamage(Gam.rangedAttack(Gon.getName()));
	std::cout << "-----------------------\n";
	Gon.beRepaired(10);
	Gon.beRepaired(50);
	std::cout << "-----------------------\n";
	while (Gon.takeDamage(Gam.vaulthunter_dot_exe(Gon.getName())))
		;
	std::cout << "-----------------------\n";
	Gun.takeDamage(Lee.rangedAttack(Gun.getName()));
	Gun.takeDamage(Lee.meleeAttack(Gun.getName()));
	std::cout << "-----------------------\n";
	Gun.beRepaired(20);
	Gun.beRepaired(40);
	std::cout << "-----------------------\n";
	for (int i = 0; i < 5; i++)
		Lee.challengeNewcomer();
	return (0);
}