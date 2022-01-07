#include "main.hpp"

int		main(void)
{
	SuperTrap Gon("gon");
	SuperTrap Gam("gam");

	std::cout << "---------------------\n";
	Gon.takeDamage(Gam.meleeAttack(Gon.getName()));
	Gon.takeDamage(Gam.rangedAttack(Gon.getName()));
	std::cout << "---------------------\n";
	while (Gon.takeDamage(Gam.vaulthunter_dot_exe(Gon.getName())))
		;
	std::cout << "---------------------\n";
	NinjaTrap Gun("gun");
	FragTrap Lee("lee");
	ScavTrap Eum("Eum");
	ClapTrap Yang("Yang");
	std::cout << "---------------------\n";
	Gon.ninjaShoebox(Gun);
	Gon.ninjaShoebox(Lee);
	Gon.ninjaShoebox(Eum);
	Gon.ninjaShoebox(Yang);
	std::cout << "---------------------\n";
	return (0);
}
