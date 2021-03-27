#ifndef PEON_HPP
# define PEON_HPP

# include <string>
# include <iostream>

# include "Victim.hpp"

class Peon : public Victim
{
	private:
		Peon();
	public:
		Peon(const std::string _name);
		Peon(const Peon& copy);
		Peon& operator=(const Peon& obj);
		virtual ~Peon();

//		std::string getName() const;
		void    getPolymorphed() const;
};

/* global operator overload */
std::ostream&	operator<<(std::ostream& out, const Peon& peon);

#endif
