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
	std::stringstream ss(request);
	std::string key;
	std::string value;
	std::string whiteSpace;

	getline(ss, value, ' ');
	this->_headers.insert( std::pair<std::string, std::string>("Type", value));
	getline(ss, value, ' ');
	this->_headers.insert( std::pair<std::string, std::string>("Path", value));
	getline(ss, value, '\r');
	getline(ss, whiteSpace, '\n');
	this->_headers.insert( std::pair<std::string, std::string>("Version", value));

	while (getline(ss, key, ':') && getline(ss, whiteSpace, ' ') && getline(ss, value, '\r')) {
		getline(ss, whiteSpace, '\n');

		// std::cout << "key:*" << key << "*" << std::endl;
		// std::cout << "value:*" << value << "*" << std::endl;
		this->_headers.insert( std::pair<std::string, std::string>(key, value));
	}
	// this->_body = key;
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
