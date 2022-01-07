#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <string>
# include <iostream>
# include <random>

class ScavTrap
{
private:
	std::string name;
	unsigned int hp;
	unsigned int maxHp;
	unsigned int ep;
	unsigned int maxEp;
	unsigned int lv;
	unsigned int MAD;
	unsigned int RAD;
	unsigned int arm;
public:
	ScavTrap();
	ScavTrap(const std::string _name);
	ScavTrap(const ScavTrap& copy);
	ScavTrap& operator=(const ScavTrap& obj);
	virtual ~ScavTrap();

	unsigned int rangedAttack(std::string const & target);
	unsigned int meleeAttack(std::string const & target);
	unsigned int takeDamage(unsigned int amount);
	unsigned int beRepaired(unsigned int amount);
	void challengeNewcomer();

	std::string getName();
};

#endif
