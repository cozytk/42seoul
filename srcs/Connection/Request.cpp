#include "Request.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

/* static variable code */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

Request::Request() {}
Request::Request(std::string const &request, bool isChuncked):
_isChuncked(isChuncked)
{
	size_t headEnd = request.find("\r\n\r\n");

	if (this->_isChuncked)
	{
		std::cout << "parsing chuncked" << std::endl;
		parseBody(request);

	}
	else {
		std::cout << "parsing header" << std::endl;
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
	// std::cout << "size: " << request.length() << " end: " << headEnd << " npos: " << std::string::npos << std::endl;
	// std::cout << "cmp: " <<  (headEnd != std::string::npos) << std::endl;
	while(tail < headEnd)
	{
		size_t colone = 0;

		head = tail + 1;
		colone = request.find(": ", head);
		tail = request.find("\r\n", colone + 2);
		std::cout << "k: " << request.substr(head, (colone) - head) << " v: " << request.substr(colone + 2, tail - (colone + 2)) << std::endl;
		this->_headers[request.substr(head, (colone) - head)] = request.substr(colone + 2, tail - (colone + 2));
	}
}

void				Request::parseBody(std::string const &body)
{
	// std::cout << "cmp: " <<  (this->_headers["Transfer-Encoding"] == "chuncked") << std::endl;
	// std::cout << "parsebody " <<  "transfer: " << this->_headers["Transfer-Encoding"] << std::endl;

	if (this->_headers["Transfer-Encoding"] == "chuncked")
	{

		this->_isChuncked = true;
	}
	if (this->_isChuncked)
	{
		int crlf = body.find("\r\n");
		if (crlf < (int)body.length() - 2)
		{
			this->_stateCode = 400;
			return ;
		}
		if (body.find("0\r\n") != std::string::npos)
			this->_isChuncked = false;
	}
	this->_body = body;
	this->_stateCode = 200;
}

Request::Request(const Request& copy)
: _headers(copy._headers), _body(copy._body), _isChuncked(copy._isChuncked)
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

bool				Request::isChuncked() {
	return (this->_isChuncked);
}
