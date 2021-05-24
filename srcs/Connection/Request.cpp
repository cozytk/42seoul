#include "Request.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

/* static variable code */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

Request::Request() {}
Request::Request(std::string const &request, bool isChunked):
_isChunked(isChunked)
{
	size_t headEnd = request.find("\r\n\r\n");
//	todo constructor should work without isChucked
	if (this->_isChunked)
		parseBody(request);
	else {
		parseHead(request);
		if (headEnd + 4 < request.length())
			parseBody(request.substr(headEnd + 4));
	}
}

void				Request::parseHead(std::string const &request) {
	size_t headEnd = request.find("\r\n\r\n");
	size_t head = 0;
	size_t tail = 0;

	// Find request type
	tail = request.find(" ");
	// while( request[tail++] != ' ');
	this->_headers[ "Type" ] = request.substr(0, tail - head);

	// Find path
	head = tail + 1;
	tail = request.find(" ", head);
	// while( request[tail++] != ' ');
	this->_headers[ "Path" ] = request.substr(head, tail - head);

	// Find HTTP version
	head = tail + 1;
	tail = request.find("\r\n", head);
	this->_headers[ "Version" ] = request.substr(head, tail - head);

	// Map all headers from a key to a value
	while(tail < headEnd)
	{
		size_t colone = 0;

		head = tail + 2;
		colone = request.find(": ", head);
		tail = request.find("\r\n", colone + 2);
		this->_headers[request.substr(head, (colone) - head)] = request.substr(colone + 2, tail - (colone + 2));
	}
}
void				Request::parseBody(std::string const &body)
{
	if (this->_headers["Transfer-Encoding"] == "chunked")
		this->_isChunked = true;
	if (this->_isChunked)
	{
		size_t crlf = body.find("\r\n");
		if (crlf == 0)
		{
			this->_stateCode = 400;
			return ;
		}
		if (body.find("0\r\n") != std::string::npos)
			this->_isChunked = false;
	}
	this->_body = body;
	this->_stateCode = 200;
}

Request::Request(const Request& copy)
: _headers(copy._headers), _body(copy._body), _isChunked(copy._isChunked)
{}

/* ************************************************************************** */
/* ------------------------------- DESTRUCTOR ------------------------------- */
/* ************************************************************************** */

Request::~Request()
{
	/* destructor code */
}

/* ************************************************************************** */
/* -------------------------------- OVERLOAD -------------------------------- */
/* ************************************************************************** */

Request& Request::operator=(const Request& obj)
{
	if (this == &obj)
		return (*this);
	/* overload= code */
	return (*this);
}

/* ************************************************************************** */
/* --------------------------------- GETTER --------------------------------- */
/* ************************************************************************** */

Request::HeaderType	Request::getHeaders()
{
	return (this->_headers);
}

std::string			Request::getBody()
{
	return (this->_body);
}

int					Request::getStateCode()
{
	return (this->_stateCode);
}

/* ************************************************************************** */
/* --------------------------------- SETTER --------------------------------- */
/* ************************************************************************** */

/* setter code */

/* ************************************************************************** */
/* ------------------------------- EXCEPTION -------------------------------- */
/* ************************************************************************** */

/* exception code */

/* ************************************************************************** */
/* ---------------------------- MEMBER FUNCTION ----------------------------- */
/* ************************************************************************** */

bool				Request::isChunked() {
	return (this->_isChunked);
}

bool				Request::isValidStart() {
	if (!isValidType() || !isValidPath() || !isValidVersion())
		return false;
	this->_stateCode = 200;
	return true;
}

bool				Request::isValidType() {
	size_t i = 0;

	while (i++ < ft::methods->length())
	{
		if (this->_headers["Type"] == ft::methods[i])
			return true;
	}
	this->_stateCode = 400;
	return false;
}

bool				Request::isValidPath() {
	if(access(this->_headers["Path"].c_str(),F_OK) == 0){
		std::cout << "path is correct." << std::endl;
		return true;
	}
	std::cout << "path is wrong." << std::endl;
	this->_stateCode = 505;
	return false;
}

bool				Request::isValidVersion() {
	if (this->_headers["Version"] == "HTTP1.1")
		return true;
	this->_stateCode = 505;
	return false;
}
