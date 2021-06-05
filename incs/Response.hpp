#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include <string>
# include "ParsedRequest.hpp"
# include "Server.hpp"
# include <webserv.hpp>
# include <cstdio>

class Response
{
	private:
		std::string		_response_body;
		std::string		_response_header;
		ParsedRequest	*_request;
		Server			*_server;
	public:
		Response();
		Response(ParsedRequest *request, Server *server);
		Response(const Response& copy);
		Response& operator=(const Response& obj);
		virtual ~Response();

		std::string	getResponseBody();
		std::string getDefaultErrorPage(ParsedRequest* request);

		std::string	runPut(ParsedRequest *request, int state);
		std::string	runGet(ParsedRequest *request);
		std::string	runPost(ParsedRequest *request);
		std::string	runDelete(ParsedRequest *request);

		void		setResponseBody(ParsedRequest *request);
		void		setCommonHeadear(ParsedRequest *request);

		std::string	response200(ParsedRequest *request);
		std::string	response400(ParsedRequest *request);
		std::string	responseCGI(ParsedRequest *request, const std::string & body);
		std::string	erase_white_space(std::string &s);
};

#endif
