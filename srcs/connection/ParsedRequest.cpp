#include "ParsedRequest.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

/* static variable code */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

ParsedRequest::ParsedRequest() {}
ParsedRequest::ParsedRequest(std::string const &request,  Config::node *config):
_config(config)
{
	size_t headEnd = request.find("\r\n\r\n");
//	todo constructor should work without isChucked
	parseHead(request);
	if (headEnd + 4 < request.length())
		parseBody(request.substr(headEnd + 4));
	RequestConfig requestConfig(this);
}

void				ParsedRequest::parseHead(std::string const &request) {
	size_t headEnd = request.find("\r\n\r\n");
	size_t head = 0;
	size_t tail = 0;

	// Find request type
	tail = request.find(" ");
	this->_headers[ "Type" ] = request.substr(0, tail - head);

	// Find path
	head = tail + 1;
	tail = request.find(" ", head);
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
void				ParsedRequest::parseBody(std::string const &body)
{
	if (isExistHeader("Transfer-Encoding") && this->_headers["Transfer-Encoding"] == "chunked")
		this->_isChunked = true;
	if (this->_isChunked)
	{
		// size_t crlf = body.find("\r\n");
		// if (crlf == 0)
		// {
		// 	this->_stateCode = 400;
		// 	return ;
		// }
		if (body.find("0\r\n") != std::string::npos)
			this->_isChunked = false;
	}
	this->_body = body;
	this->_stateCode = 200;
}

ParsedRequest::ParsedRequest(const ParsedRequest& copy)
: _headers(copy._headers), _body(copy._body), _isChunked(copy._isChunked)
{}

/* ************************************************************************** */
/* ------------------------------- DESTRUCTOR ------------------------------- */
/* ************************************************************************** */

ParsedRequest::~ParsedRequest()
{
	/* destructor code */
}

/* ************************************************************************** */
/* -------------------------------- OVERLOAD -------------------------------- */
/* ************************************************************************** */

ParsedRequest& ParsedRequest::operator=(const ParsedRequest& obj)
{
	if (this == &obj)
		return (*this);
	/* overload= code */
	return (*this);
}

/* ************************************************************************** */
/* --------------------------------- GETTER --------------------------------- */
/* ************************************************************************** */

ParsedRequest::HeaderType	&ParsedRequest::getHeaders()
{
	return (this->_headers);
}

std::string			ParsedRequest::getBody()
{
	return (this->_body);
}

std::string			ParsedRequest::getRoot()
{
	return (this->_root);
}

int					ParsedRequest::getStateCode()
{
	return (this->_stateCode);
}

Config::node *		ParsedRequest::getConfig()
{
	return (this->_config);
}

/* ************************************************************************** */
/* --------------------------------- SETTER --------------------------------- */
/* ************************************************************************** */

void				ParsedRequest::setStateCode(int state)
{
	this->_stateCode = state;
}

/* ************************************************************************** */
/* ------------------------------- EXCEPTION -------------------------------- */
/* ************************************************************************** */

/* exception code */

/* ************************************************************************** */
/* ---------------------------- MEMBER FUNCTION ----------------------------- */
/* ************************************************************************** */

bool				ParsedRequest::isChunked() {
	return (this->_isChunked);
}

bool				ParsedRequest::isExistHeader(std::string in) {
	if (this->_headers.find(in) == this->_headers.end())
		return false;
	return true;
}
