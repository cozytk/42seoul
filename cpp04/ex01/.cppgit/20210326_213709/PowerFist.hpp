#ifndef POWER_FIST_HPP
# define POWER_FIST_HPP

# include <string>
# include <iostream>

class PowerFist
{
	private:
		/* declare member variable */
	public:
		PowerFist();
		PowerFist(const std::string& /* parameter */, ...);
		PowerFist(const PowerFist& copy);
		PowerFist& operator=(const PowerFist& obj);
		virtual ~PowerFist();

		/* declare member function */
};

/* global operator overload */
std::ostream&	operator<<(std::ostream& out, const PowerFist& powerFist);

#endif
