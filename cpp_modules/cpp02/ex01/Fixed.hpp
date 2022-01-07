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
		Fixed(int const val);
		Fixed(float const val);
		Fixed& operator=(const Fixed& obj);
		virtual ~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const _val);
		float   toFloat(void) const;
		int     toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed &ref);

#endif
