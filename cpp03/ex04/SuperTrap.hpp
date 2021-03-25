#ifndef SUPER_TRAP_HPP
# define SUPER_TRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"
# include "NinjaTrap.hpp"
# include "FragTrap.hpp"

class SuperTrap : public virtual FragTrap, public virtual NinjaTrap
{
	private:
		/* declare member variable */
	public:
		SuperTrap();
		SuperTrap(const std::string);
		SuperTrap(const SuperTrap& copy);
		SuperTrap& operator=(const SuperTrap& obj);
		virtual ~SuperTrap();

		unsigned int	rangedAttack(std::string const & target);
		unsigned int	meleeAttack(std::string const & target);
		/* declare member function */
};


#endif
