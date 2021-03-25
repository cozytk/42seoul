#ifndef TEST_HPP
# define TEST_HPP

# include <string>
# include <iostream>

class Test
{
	private:
		/* declare member variable */
	public:
		Test();
		Test(const std::string& /* parameter */, ...);
		Test(const Test& copy);
		Test& operator=(const Test& obj);
		virtual ~Test();

		/* declare member function */
};

/* global operator overload */
std::ostream&	operator<<(std::ostream& out, const Test& test);

#endif
