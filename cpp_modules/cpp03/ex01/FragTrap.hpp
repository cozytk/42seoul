#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <string>
# include <iostream>
# include <random>

class FragTrap
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
	FragTrap();
	FragTrap(const std::string _name);
	FragTrap(const FragTrap& copy);
	FragTrap& operator=(const FragTrap& obj);
	virtual ~FragTrap();

	unsigned int rangedAttack(std::string const & target);
	unsigned int meleeAttack(std::string const & target);
	unsigned int takeDamage(unsigned int amount);
	unsigned int beRepaired(unsigned int amount);
	unsigned int vaulthunter_dot_exe(std::string const & target);

	std::string getName();
};

#endif
