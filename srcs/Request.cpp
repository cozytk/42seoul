#include "Request.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

/* static variable code */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

Request::Request() {}
// TODO add fd parameter
Request::Request(std::string const &request){
	std::string copyReq(request);
	int head = 0;
	int tail = 0;

	// Find request type
	while( copyReq[tail++] != ' ');
	this->_headers[ "Type" ] = copyReq.substr( 0 , ( tail - 1) - head );

	// Find path
	head = tail;
	while( copyReq[tail++] != ' ');
	this->_headers[ "Path" ] = copyReq.substr( head, ( tail - 1) - head );

	// Find HTTP version
	head = tail;
	while( copyReq[tail++] != '\r');
	this->_headers[ "Version" ] = copyReq.substr( head, ( tail - 1) - head );
	tail++;
	// Map all headers from a key to a value
	while(tail + 3 < (int)copyReq.length() &&
	(copyReq[tail] != '\r' || copyReq[tail + 1] != '\n' || copyReq[tail + 2] != '\r' || copyReq[tail + 3] != '\n'))
	{
		int colone = 0;
		head = tail++;
		while( copyReq[tail] != '\r' || copyReq[tail + 1] != '\n')
		{
			if (copyReq[tail] == ':' && copyReq[tail + 1] == ' ')
				colone = tail;
			tail++;
		}
		this->_headers[copyReq.substr(head, (colone) - head)] = copyReq.substr( colone + 2, tail - (colone + 2));
	}
	if (tail + 4 < (int)copyReq.length())
	{
		tail = tail + 4;
		this->_body = copyReq.substr( tail, copyReq.length() - tail);
	}
}

Request::Request(const Request& copy)
: _headers(copy._headers), _body(copy._body)
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

/* getter code */

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

bool				Request::isValid() {
	return (true);
}
Request::HeaderType	Request::getHeaders() {
	return (this->_headers);
}
std::string			Request::getBody() {
	return (this->_body);
}
