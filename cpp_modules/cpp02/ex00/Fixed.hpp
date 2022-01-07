#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class Fixed
{
	private:
		int					val;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& obj);
		virtual ~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const _val);
};

/* global operator overload */

#endif
