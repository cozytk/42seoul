#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include <string>
# include "ParsedRequest.hpp"
# include "AutoIndex.hpp"
# include "Server.hpp"
# include "CGI.hpp"
# include <webserv.hpp>
# include <cstdio>

class Server;
class Response
{
	private:
		std::string		_response_body;
		std::string		_response_header;
		ParsedRequest	*_request;
		Server			*_server;
		static std::map<std::string, std::string> _mime_types;
		static std::map<int, std::string> _status;
	public:
		Response();
		Response(ParsedRequest *request, Server *server);
		Response(const Response& copy);
		Response& operator=(const Response& obj);
		virtual ~Response();

		std::string	getResponseBody();
		std::string getState(ParsedRequest* request);
		std::string getDefaultErrorPage(ParsedRequest* request);
		std::string getServerHeader(ParsedRequest *request);
		std::string getDateHeader(ParsedRequest *request);
		std::string getContentTypeHeader(ParsedRequest *request);
		std::string getContentLengthHeader(ParsedRequest *request);
		std::string getLastModifiedHeader(ParsedRequest *request);
		std::string getConnectionHeader(ParsedRequest *request);
		std::string getStateText(int state);
		std::string getResponse(AutoIndex &autoindex, CGI &cgi);

		std::string	runPut(ParsedRequest *request);
		std::string	runGet(ParsedRequest *request);
		std::string	runPost(ParsedRequest *request);
		std::string	runDelete(ParsedRequest *request);
		std::string runCGI(ParsedRequest *request, std::string &cgi_body);

		void		setResponseBody(ParsedRequest *request);
		void		setCommonHeadear(ParsedRequest *request);
		void        setResponseHeadear(std::vector<std::string> &headers, ParsedRequest *request);

		std::string	response200(ParsedRequest *request);
		std::string	response400(ParsedRequest *request);
		std::string	erase_white_space(std::string &s);
};

#endif
