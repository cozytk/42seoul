#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>

class Character
{
	private:
		/* declare member variable */
	public:
		Character();
		Character(const std::string& /* parameter */, ...);
		Character(const Character& copy);
		Character& operator=(const Character& obj);
		virtual ~Character();

		/* declare member function */
};

/* global operator overload */
std::ostream&	operator<<(std::ostream& out, const Character& character);

#endif
