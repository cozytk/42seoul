#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class Fixed
{
	private:
		int					val;
		static const int	bits;
	public:
		Fixed();
		Fixed(const std::string& /* parameter */, ...);
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& obj);
		virtual ~Fixed();

		/* declare member function */
};

/* global operator overload */
std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);

#endif
