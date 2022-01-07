#ifndef NINJA_TRAP_HPP
# define NINJA_TRAP_HPP

# include <string>
# include <iostream>

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class NinjaTrap : public ClapTrap
{
private:
	/* declare member variable */
public:
	NinjaTrap();
	NinjaTrap(const std::string);
	NinjaTrap(const NinjaTrap& copy);
	NinjaTrap& operator=(const NinjaTrap& obj);
	virtual ~NinjaTrap();

	void ninjaShoebox(FragTrap const & target) const;
	void ninjaShoebox(NinjaTrap const & target) const;
	void ninjaShoebox(ClapTrap const & target) const;
	void ninjaShoebox(ScavTrap const & target) const;
};

#endif
