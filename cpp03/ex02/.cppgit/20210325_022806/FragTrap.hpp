#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <string>
# include <iostream>

class FragTrap
{
	private:
		/* declare member variable */
	public:
		FragTrap();
		FragTrap(const std::string& /* parameter */, ...);
		FragTrap(const FragTrap& copy);
		FragTrap& operator=(const FragTrap& obj);
		virtual ~FragTrap();

		/* declare member function */
};

/* global operator overload */
std::ostream&	operator<<(std::ostream& out, const FragTrap& fragTrap);

#endif
