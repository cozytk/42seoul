#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <string>
# include <iostream>
# include <random>

class ClapTrap
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
	std::string type;
public:
	ClapTrap();
	ClapTrap(const std::string);
	ClapTrap(const ClapTrap& copy);
	ClapTrap& operator=(const ClapTrap& obj);
	virtual ~ClapTrap();
	unsigned int rangedAttack(std::string const & target);
	unsigned int meleeAttack(std::string const & target);
	unsigned int takeDamage(unsigned int amount);
	unsigned int beRepaired(unsigned int amount);
	std::string getName();
};

#endif
