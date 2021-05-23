#ifndef REQUEST_HPP
# define REQUEST_HPP

# include <string>
# include <map>
# include <iostream>
# include <vector>
# include <utility>
#include <cstring>
#include <sstream>
class Request
{
	public:
	typedef	std::map<std::string, std::string> HeaderType;
	private:
		HeaderType	_headers;
		std::string	_body;
		bool		_isChunked;
		int			_stateCode;

		void parseBody(std::string const &body);
		void parseHead(std::string const &request);
	public:
		Request();
		Request(std::string const &request, bool isChunked);
		Request(const Request& copy);
		Request& operator=(const Request& obj);
		virtual ~Request();

		int			getStateCode();
		bool		isChunked();
		HeaderType	getHeaders();
		std::string	getBody();
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
