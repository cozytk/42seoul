#include "Request.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

/* static variable code */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

Request::Request()
{
	_method = DEFAULT;
}
Request::Request(std::string const &request, bool isChuncked):
		_isChuncked(isChuncked)
{
	std::string copyReq(request);
	int headEnd = copyReq.find("\r\n\r\n");
	int head = 0;
	int tail = 0;

	// Find request type
	tail = copyReq.find(" ");
	// while( copyReq[tail++] != ' ');
	this->_headers[ "Type" ] = copyReq.substr(0, tail - head);

	// Find path
	head = tail + 1;
	tail = copyReq.find(" ", head);
	// while( copyReq[tail++] != ' ');
	this->_headers[ "Path" ] = copyReq.substr(head, tail - head);

	// Find HTTP version
	head = tail + 1;
	tail = copyReq.find("\r\n", head);
	this->_headers[ "Version" ] = copyReq.substr(head, tail - head);

	// Map all headers from a key to a value
	while(tail < headEnd)
	{
		int colone = 0;

		head = tail + 1;
		colone = copyReq.find(": ", head);
		tail = copyReq.find("\r\n", colone + 2);
		this->_headers[copyReq.substr(head, (colone) - head)] = copyReq.substr(colone + 2, tail - (colone + 2));
	}
	if (this->_isChuncked)
		parseBody(copyReq);
	else if (headEnd + 4 < (int) copyReq.length())
		parseBody(copyReq.substr(headEnd + 4));
}

void				Request::parseBody(std::string const &body)
{
	if (this->_headers["Transfer-encoding"] == "encoding")
		this->_isChuncked = true;
	if (this->_isChuncked)
	{
		int crlf = body.find("\r\n");
		if (crlf < body.length() - 2)
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
{
	/* copy-constructor code */
}

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

Request::Method			Request::get_method() const
{
	return (_method);
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

bool				Request::isValid()
{
	return (true);
}