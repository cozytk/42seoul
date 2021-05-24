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
	enum Method { DEFAULT, GET, HEAD, POST, PUT, DELETE, OPTIONS, TRACE };
	typedef	std::map<std::string, std::string> HeaderType;
private:
	Method _method;
	std::string	_version;
	HeaderType	_headers;
	std::string	_body;
	bool		_isChuncked;
	int			_stateCode;

	void parseBody(std::string const &body);
public:
	Request();
	Request(std::string const &request, bool isChuncked);
	Request(const Request& copy);
	Request& operator=(const Request& obj);
	virtual ~Request();

	bool		isValid();
	HeaderType	getHeaders();
	std::string	getBody();
	Method get_method() const;
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