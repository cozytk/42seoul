#ifndef PARSED_REQUEST_HPP
# define PARSED_REQUEST_HPP

# include <string>
# include <map>
# include <iostream>
# include <vector>
# include <utility>
# include <cstring>
# include <sys/stat.h>
# include <unistd.h>
# include <unistd.h>
# include "Config.hpp"
# include "WebServerConstant.hpp"

class ParsedRequest
{
	public:
	typedef	std::map<std::string, std::string> HeaderType;
	private:
		HeaderType		_headers;
		std::string		_body;
		bool			_isChunked;
		int				_stateCode;
		Config::node *	_config;

		void			parseBody(std::string const &body);
		void			parseHead(std::string const &request);

	public:
		ParsedRequest();
		ParsedRequest(std::string const &request, Config::node *config);
		ParsedRequest(const ParsedRequest& copy);
		ParsedRequest& operator=(const ParsedRequest& obj);
		virtual ~ParsedRequest();

		int					getStateCode();
		HeaderType			&getHeaders();
		std::string			getBody();
		Config::node *		getConfig();

		void				setStateCode(int state);

		bool				isChunked();
		bool				isExistHeader(std::string in);

};
//Accept-Charsets
//Accept-Language
//Allow
//Authorization
//Content-Language
//Content-Length
//Content-Location
//Content-Type
//Date
//Host
//Last-Modified
//Location
//Referer
//Retry-After
//Server
//Transfer-Encoding
//User-Agent
//WWW-Authenticate

// GET
// HEAD
// POST
// PUT
// DELETE
// CONNECT
// OPTIONS
// TRACE

#endif
