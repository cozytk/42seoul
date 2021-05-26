#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include <string>
# include <iostream>

# define GET 1
# define HEAD 0

#include "../incs/webserv.hpp"
#include "connection/Request.hpp"

class Response
{
	public:
		typedef std::vector<std::string> headers_t;
	private:
		std::map<std::string, std::string> _headers;
	public:
		Response();
		Response(const std::string& /* parameter */, ...);
		Response(const Response& copy);
		Response& operator=(const Response& obj);
		virtual ~Response();

		/* declare member function */

		void sortMethod(Connection& connection, const Request& request);
		void response100(Connection& connection, int status, headers_t headers, std::string body);
		void response200(Connection& connection, int status, headers_t headers, std::string body);
		void response300(Connection& connection, int status, headers_t headers, std::string body);
		void response400(Connection& connection, int status, headers_t headers, std::string body);
		void response500(Connection& connection, int status, headers_t headers, std::string body);
		std::string fileToString(std::string path, int limit)
};

/* global operator overload */
std::ostream&	operator<<(std::ostream& out, const Response& response);

#endif
