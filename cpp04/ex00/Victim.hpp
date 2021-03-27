#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <string>
# include <iostream>

class Victim
{
protected:
	std::string name;
	Victim();
public:
	Victim(const std::string _name);
	Victim(const Victim& copy);
	Victim& operator=(const Victim& obj);
	virtual ~Victim();

	std::string getName() const;
	virtual void getPolymorphed() const;
};

/* global operator overload */
std::ostream&	operator<<(std::ostream& out, const Victim& victim);

#endif
