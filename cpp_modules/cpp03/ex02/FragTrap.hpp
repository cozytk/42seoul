#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <string>
# include <iostream>

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	/* declare member variable */
public:
	FragTrap();
	FragTrap(const std::string);
	FragTrap(const FragTrap& copy);
	FragTrap& operator=(const FragTrap& obj);
	virtual ~FragTrap();

	unsigned int vaulthunter_dot_exe(std::string const & target);
};

#endif
