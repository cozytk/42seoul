#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <string>
# include <iostream>

class ScavTrap
{
	private:
		/* declare member variable */
	public:
		ScavTrap();
		ScavTrap(const std::string& /* parameter */, ...);
		ScavTrap(const ScavTrap& copy);
		ScavTrap& operator=(const ScavTrap& obj);
		virtual ~ScavTrap();

		/* declare member function */
};

/* global operator overload */
std::ostream&	operator<<(std::ostream& out, const ScavTrap& scavTrap);

#endif
