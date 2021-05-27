#ifndef SAYI_REQUEST_HPP
# define SAYI_REQUEST_HPP

# include <string>
# include <map>
# include <iostream>
# include <vector>
# include <utility>
# include <cstring>
 #include <sys/stat.h>
# include <unistd.h>
# include "WebServerConstant.hpp"

class SayiRequest
{
	public:
	typedef	std::map<std::string, std::string> HeaderType;
	private:
		HeaderType	_headers;
		std::string	_body;
		bool		_isChunked;
		int			_stateCode;

		void		parseBody(std::string const &body);
		void		parseHead(std::string const &request);

		bool		isValidStart();
		bool		isValidType();
		bool		isValidPath();
		bool		isValidVersion();

		// bool		isValidContent();
		bool		isAllowedMethod();
	public:
		SayiRequest();
		SayiRequest(std::string const &request, bool isChunked);
		SayiRequest(const SayiRequest& copy);
		SayiRequest& operator=(const SayiRequest& obj);
		virtual ~SayiRequest();

		int			getStateCode();
		HeaderType	getHeaders();
		std::string	getBody();

		bool		isChunked();
		bool		isValid();
		bool		isExistHeader(std::string in);

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
