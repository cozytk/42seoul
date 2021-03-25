#ifndef DEST_HPP
# define DEST_HPP

# include <string>
# include <iostream>

class Dest
{
	private:
		/* declare member variable */
	public:
		Dest();
		Dest(const std::string& /* parameter */, ...);
		Dest(const Dest& copy);
		Dest& operator=(const Dest& obj);
		virtual ~Dest();

		/* declare member function */
};

/* global operator overload */
std::ostream&	operator<<(std::ostream& out, const Dest& dest);

#endif
