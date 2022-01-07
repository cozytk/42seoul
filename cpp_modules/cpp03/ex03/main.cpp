#include "main.hpp"

int		main(void)
{
	FragTrap Gon("gon");
	FragTrap Gam("gam");
	ScavTrap Gun("gun");
	ScavTrap Lee("lee");
	NinjaTrap Eum("eum");
	NinjaTrap Yang("Yang");

	std::cout << "-----------------------\n";
	Gon.takeDamage(Gam.meleeAttack(Gon.getName()));
	Gon.takeDamage(Gam.rangedAttack(Gon.getName()));
	std::cout << "-----------------------\n";
	Gon.beRepaired(10);
	std::cout << "-----------------------\n";
	while (Gon.takeDamage(Gam.vaulthunter_dot_exe(Gon.getName())))
		;
	std::cout << "-----------------------\n";
	Gun.takeDamage(Lee.rangedAttack(Gun.getName()));
	Gun.takeDamage(Lee.meleeAttack(Gun.getName()));
	std::cout << "-----------------------\n";
	Gun.beRepaired(20);
	std::cout << "-----------------------\n";
	for (int i = 0; i < 5; i++)
		Lee.challengeNewcomer();
	std::cout << "-----------------------\n";
	Eum.takeDamage(Yang.rangedAttack(Eum.getName()));
	std::cout << "-----------------------\n";
	Yang.beRepaired(10);
	std::cout << "-----------------------\n";
	Yang.ninjaShoebox(Gon);
	Yang.ninjaShoebox(Lee);
	Yang.ninjaShoebox(Eum);
	std::cout << "-----------------------\n";
	return (0);
}