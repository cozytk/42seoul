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

ParsedRequest::HeaderType	ParsedRequest::getHeaders()
{
	return (this->_headers);
}

std::string			ParsedRequest::getBody()
{
	return (this->_body);
}

int					ParsedRequest::getStateCode()
{
	return (this->_stateCode);
}

//std::string         Request::getMethod()
//{
//	return (this->_methods);
//}
//
//
//std::string Request::getUriType()
//{
//	return (this->_uritype);
//}

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


bool				ParsedRequest::isValidStart() {
	if (!isValidType() || !isValidPath() || !isValidVersion())
		return false;
	this->_stateCode = 200;
	return true;
}

bool				ParsedRequest::isValidType() {
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
		if (this->_headers["Type"] == _methods[i])
			return true;
	}
	// get, head can't be 405
	// todo should check server support method if not return 405
	this->_stateCode = 400;
	return false;
}

bool				ParsedRequest::isValidPath() {
	std::string path;
	struct stat s;
	std::string res;

		//
		int i = 0;
	std::cout << "configing" << std::endl;
	std::cout << "server size: " << (*_config).size("location") << std::endl;
	Config::node node;
	node = (*_config);
	std::cout << "get location: " << node.size("location") << std::endl;
	std::vector<std::string> v;
	i = 0;
	while (i < node.size("location"))
	{
		std::cout << i << " th:" << (*node("location", i))[0] << std::endl;
		if ((*node("location", i))[0] == "/")
		{

			std::cout << "got cat" << std::endl;
			v = *(*_config)("http", 0)("server")("location", i);
		}
		i++;
	}


	i = 0;
	std::cout << "location size: " << v.size() << std::endl;
	while (i < v.size())
	{
		std::cout << i << "th: " << v[i] << std::endl;
		i++;
	}
	//
	if(!isExistHeader("Path")){
		this->_stateCode = 400;
		return false;
	}
	path = "." +this->_headers["Path"];
	if( stat(path.c_str(),&s) == 0 )
	{
	    if( s.st_mode & S_IFDIR )
	    {
			if (path[(int)path.length() - 1] != '/')
				path = path + "/";
			path = path + "index.html";
	    }
	    else if( s.st_mode & S_IFREG )
	    {
			if (path.find(".bla") != std::string::npos ||
			path.find(".bad_extension") != std::string::npos)
				std::cout << "need cgi run" << std::endl;
	    }
		this->_stateCode = 200;
		// this->_headers["Path"] = path;
		return true;
	}
	this->_stateCode = 404;
	return false;
}

bool				ParsedRequest::isValidVersion() {
	if (isExistHeader("Version") && this->_headers["Version"] == "HTTP/1.1")
		return true;
	this->_stateCode = 505;
	return false;
}

// bool				ParsedRequest::isValidContent() {
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

bool				ParsedRequest::isAllowedMethod() {
	if (this->_headers["Path"] == "/" && this->_headers["Type"] != "GET") {
		this->_stateCode = 405;
		return false;
	}
	return true;
}

bool				ParsedRequest::isChunked() {
	return (this->_isChunked);
}

bool				ParsedRequest::isValid() {
	if (!isValidStart())
		return false;
	// if (!isValidContent())
	// 	return false;
	if (!isAllowedMethod())
		return false;
	this->_stateCode = 200;
	return true;
}

bool				ParsedRequest::isExistHeader(std::string in) {
	if (this->_headers.find(in) == this->_headers.end())
		return false;
	return true;
}

std::string Request::getPathTranslated() const
{
	return (_pathTranslated);
}
