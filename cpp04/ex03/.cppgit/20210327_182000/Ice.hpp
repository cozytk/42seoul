#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include <iostream>

class Ice
{
	private:
		/* declare member variable */
	public:
		Ice();
		Ice(const std::string& /* parameter */, ...);
		Ice(const Ice& copy);
		Ice& operator=(const Ice& obj);
		virtual ~Ice();

		/* declare member function */
};

/* global operator overload */
std::ostream&	operator<<(std::ostream& out, const Ice& ice);

#endif
