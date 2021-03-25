#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <string>
# include <iostream>

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	/* declare member variable */
public:
	ScavTrap();
	ScavTrap(const std::string _name);
	ScavTrap(const ScavTrap& copy);
	ScavTrap& operator=(const ScavTrap& obj);
	virtual ~ScavTrap();

	void challengeNewcomer();
		/* declare member function */
};


#endif
