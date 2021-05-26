#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include <string>
# include <iostream>

class Response
{
	private:
		/* declare member variable */
	public:
		Response();
		Response(const std::string& /* parameter */, ...);
		Response(const Response& copy);
		Response& operator=(const Response& obj);
		virtual ~Response();

		/* declare member function */
};

/* global operator overload */
std::ostream&	operator<<(std::ostream& out, const Response& response);

#endif
