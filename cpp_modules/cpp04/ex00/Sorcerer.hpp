#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <string>
# include <iostream>

class Sorcerer
{
private:
	std::string name;
	std::string title;
	Sorcerer();
public:
	Sorcerer(const std::string _name, const std::string _title);
	Sorcerer(const Sorcerer& copy);
	Sorcerer& operator=(const Sorcerer& obj);
	virtual ~Sorcerer();

	std::string getName() const;
	std::string getTitle() const;
	void polymorph(Victim const & victim) const;
};

/* global operator overload */
std::ostream&	operator<<(std::ostream& out, const Sorcerer& sorcerer);

#endif
