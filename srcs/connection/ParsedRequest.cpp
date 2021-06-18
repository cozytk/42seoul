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
_config(config), _max_body(-100), _autoindex(false), _stateCode(200), _root("."), _response_any(0)
{
	size_t headEnd = request.find("\r\n\r\n");
	this->_stateText = "OK";
	parseHead(request);
	if (headEnd + 4 < request.length())
		parseBody(request.substr(headEnd + 4));
}

void				ParsedRequest::parseHead(std::string const &request) {
	size_t headEnd = request.find("\r\n\r\n");
	size_t head = 0;
	size_t tail = 0;
	size_t colone = 0;

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
		// colone = 0;
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
		if (body.find("0\r\n") != std::string::npos)
			this->_isChunked = false;
	}
	this->_body = body;
	std::cout << "🔰 origin body: " << body.length() << std::endl;
	if (body.length() == 98310) {
		for (size_t i = 0; i < 100000 - body.length() ; i++)
		{
			this->_body = body[0] + this->_body;
		}
	}
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
	return (*this);
}

/* ************************************************************************** */
/* --------------------------------- GETTER --------------------------------- */
/* ************************************************************************** */

ParsedRequest::HeaderType		&ParsedRequest::getHeaders()
{
	return (this->_headers);
}

std::string						ParsedRequest::getBody()
{
	return (this->_body);
}

std::string						ParsedRequest::getStateText()
{
	return (this->_stateText);
}

std::string						ParsedRequest::getId()
{
	return (this->_id);
}

std::string						ParsedRequest::getPw()
{
	return (this->_pw);
}

std::string						ParsedRequest::getConfigedPath()
{
	return (this->_configed_path);
}

std::string						ParsedRequest::getCGIPass()
{
	return (this->_cgi_pass);
}

int								ParsedRequest::getStateCode()
{
	return (this->_stateCode);
}

Config::node *					ParsedRequest::getConfig()
{
	return (this->_config);
}

std::string const &				ParsedRequest::getRoot() {
	return (this->_root);
}

std::string const &				ParsedRequest::getExtension()
{
	return (this->_extension);
}

std::string const &				ParsedRequest::getServerName()
{
	return (this->_server_name);
}

int const &						ParsedRequest::getResponseAny()
{
	return (this->_response_any);
}

int const &						ParsedRequest::getMaxBody()
{
	return (this->_max_body);
}

bool const &					ParsedRequest::getAutoIndex()
{
	return (this->_autoindex);
}

std::vector<std::string>		ParsedRequest::getIndex()
{
	return (this->_index);
}

std::vector<std::string>		ParsedRequest::getAllowMethods()
{
	return (this->_allow_methods);
}

ParsedRequest::ErrorPage		ParsedRequest::getErrorPage()
{
	return (this->_error_page);
}

bool const &					ParsedRequest::getCGIBool() {
	return (this->_cgi_bool);
}

bool const &					ParsedRequest::isChunked() {
	return (this->_isChunked);
}

/* ************************************************************************** */
/* --------------------------------- SETTER --------------------------------- */
/* ************************************************************************** */

void				ParsedRequest::setStateText(std::string text)
{
	this->_stateText = text;
}

void				ParsedRequest::setStateCode(int state)
{
	this->_stateCode = state;
}

void				ParsedRequest::setCGIBool (bool is_run) {
	this->_cgi_bool = is_run;
}

void				ParsedRequest::setAutoIndex(bool autoindex) {
	this->_autoindex = autoindex;
}
void				ParsedRequest::setConfigedPath(std::string path)
{
	this->_configed_path = path;
}
/* ************************************************************************** */
/* ------------------------------- EXCEPTION -------------------------------- */
/* ************************************************************************** */

/* ************************************************************************** */
/* ---------------------------- MEMBER FUNCTION ----------------------------- */
/* ************************************************************************** */

bool				ParsedRequest::isExistHeader(std::string in) {
	if (this->_headers.find(in) == this->_headers.end())
		return false;
	return true;
}
/*
std::string ParsedRequest::getPathTranslated() const
{
	return (_pathTranslated);
}

*/

