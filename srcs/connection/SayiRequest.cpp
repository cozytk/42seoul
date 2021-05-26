#include "SayiRequest.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

/* static variable code */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

SayiRequest::SayiRequest() {}
SayiRequest::SayiRequest(std::string const &request, bool isChunked):
_isChunked(isChunked)
{
	size_t headEnd = request.find("\r\n\r\n");
//	todo constructor should work without isChucked
	parseHead(request);
	if (headEnd + 4 < request.length())
		parseBody(request.substr(headEnd + 4));
}

void				SayiRequest::parseHead(std::string const &request) {
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
void				SayiRequest::parseBody(std::string const &body)
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

SayiRequest::SayiRequest(const SayiRequest& copy)
: _headers(copy._headers), _body(copy._body), _isChunked(copy._isChunked)
{}

/* ************************************************************************** */
/* ------------------------------- DESTRUCTOR ------------------------------- */
/* ************************************************************************** */

SayiRequest::~SayiRequest()
{
	/* destructor code */
}

/* ************************************************************************** */
/* -------------------------------- OVERLOAD -------------------------------- */
/* ************************************************************************** */

SayiRequest& SayiRequest::operator=(const SayiRequest& obj)
{
	if (this == &obj)
		return (*this);
	/* overload= code */
	return (*this);
}

/* ************************************************************************** */
/* --------------------------------- GETTER --------------------------------- */
/* ************************************************************************** */

SayiRequest::HeaderType	SayiRequest::getHeaders()
{
	return (this->_headers);
}

std::string			SayiRequest::getBody()
{
	return (this->_body);
}

int					SayiRequest::getStateCode()
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


bool				SayiRequest::isValidStart() {
	if (!isValidType() || !isValidPath() || !isValidVersion())
		return false;
	this->_stateCode = 200;
	return true;
}

bool				SayiRequest::isValidType() {
	size_t i = -1;
	std::string	methods[8] = {
		"GET",
		"HEAD",
		"POST",
		"PUT",
		"DELETE",
		"CONNECT",
		"OPTIONS",
		"TRACE"
	};
	if (!isExistHeader("Type"))
	{
		this->_stateCode = 400;
		return false;
	}
	while (++i < 8)
	{
		if (this->_headers["Type"] == methods[i])
			return true;
	}
	// get, head can't be 405
	// todo should check server support method if not return 405
	this->_stateCode = 400;
	return false;
}

bool				SayiRequest::isValidPath() {
	std::string path("." +this->_headers["Path"]);
	if (path[(int)path.length() - 1] != '/')
	{
		if (path.find(".bla") != std::string::npos)
		{

		}
		else
			path = path + "/index.html";
	}
	else
		path = path + "index.html";
	std::cout << "path check index: " << path << std::endl;
	if(isExistHeader("Path") && access(path.c_str(),F_OK) == 0){
		std::cout << "path is correct." << std::endl;
		return true;
	}
	std::cout << "path is wrong." << std::endl;
	this->_stateCode = 404;
	return false;
}

bool				SayiRequest::isValidVersion() {
	if (isExistHeader("Version") && this->_headers["Version"] == "HTTP/1.1")
		return true;
	this->_stateCode = 505;
	return false;
}

// bool				SayiRequest::isValidContent() {
// 	std::string method = ;
// 	// post, put without content-length 411, 400
// 	this->_stateCode = 200;
// 	if (this->_headers["Type"] == ft::methods[POST] || method == ft::methods[PUT]) {
// 		if (isExistHeader("Content-Length")) {
// 			// ignore content-length since transfer-encoding contained
// 			if (isExistHeader("Transfer-Encoding") && this->_headers["Transfer-Encoding"] != "identity")
// 				return true;
// 			// todo need stoi to check
// 			if (this->_headers["Content-Length"] == this->_body.length())
// 				return true;
// 			// bad request
// 			this->_stateCode = 400;
// 			return false;
// 		}
// 		// request should contain content-length
// 		this->_stateCode = 411;
// 		return false;
// 	}
// 	return true;
// }

bool				SayiRequest::isAllowedMethod() {
	if (this->_headers["Path"] == "/" && this->_headers["Type"] != "GET") {
		this->_stateCode = 405;
		return false;
	}
	return true;
}

bool				SayiRequest::isChunked() {
	return (this->_isChunked);
}

bool				SayiRequest::isValid() {
	if (!isValidStart())
		return false;
	// if (!isValidContent())
	// 	return false;
	if (!isAllowedMethod())
		return false;
	this->_stateCode = 200;
	return true;
}

bool				SayiRequest::isExistHeader(std::string in) {
	if (this->_headers.find(in) == this->_headers.end())
		return false;
	return true;
}
