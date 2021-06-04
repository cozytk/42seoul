#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include <string>
# include "ParsedRequest.hpp"
# include <webserv.hpp>

class Response
{
	private:
		std::string		_response;
		ParsedRequest	*_request;
	public:
		Response();
		Response(ParsedRequest *request);
		Response(const Response& copy);
		Response& operator=(const Response& obj);
		virtual ~Response();

		std::string	getResponse();

		std::string	runPut(ParsedRequest *request, int state);
};

#endif
