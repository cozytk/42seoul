#ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include <iostream>

class Cure
{
	private:
		/* declare member variable */
	public:
		Cure();
		Cure(const std::string& /* parameter */, ...);
		Cure(const Cure& copy);
		Cure& operator=(const Cure& obj);
		virtual ~Cure();

		/* declare member function */
};

/* global operator overload */
std::ostream&	operator<<(std::ostream& out, const Cure& cure);

#endif
