#include "RequestInspect.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

/* static variable code */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

RequestInspect::RequestInspect() {}

RequestInspect::RequestInspect(const RequestInspect& copy)
{}

RequestInspect::RequestInspect(ParsedRequest *req):
_req(req)
{
}
/* ************************************************************************** */
/* ------------------------------- DESTRUCTOR ------------------------------- */
/* ************************************************************************** */

RequestInspect::~RequestInspect() {}

/* ************************************************************************** */
/* -------------------------------- OVERLOAD -------------------------------- */
/* ************************************************************************** */

RequestInspect& RequestInspect::operator=(const RequestInspect& obj)
{
	if (this == &obj)
		return (*this);
	return (*this);
}

/* ************************************************************************** */
/* --------------------------------- GETTER --------------------------------- */
/* ************************************************************************** */

/* ************************************************************************** */
/* --------------------------------- SETTER --------------------------------- */
/* ************************************************************************** */

/* ************************************************************************** */
/* ------------------------------- EXCEPTION -------------------------------- */
/* ************************************************************************** */

/* ************************************************************************** */
/* ---------------------------- MEMBER FUNCTION ----------------------------- */
/* ************************************************************************** */


bool				RequestInspect::isValidStart() {
	if (!isValidType() || !isValidPath() || !isValidVersion())
		return false;
	return true;
}

bool				RequestInspect::isValidType() {
	ParsedRequest::HeaderType &header = _req->getHeaders();
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
	if (!_req->isExistHeader("Type"))
	{
		this->_req->setStateCode(400);
		this->_req->setStateText("Bad Request");
		return false;
	}
	while (++i < 8)
	{
		if (header["Type"] == methods[i])
			return true;
	}
	// get, head can't be 405 but tester approve accessing '/' only get
	// todo should check server support method if not return 405
	this->_req->setStateCode(400);
	this->_req->setStateText("Bad Request");
	return false;
}

bool				RequestInspect::isValidPath() {
	ParsedRequest::HeaderType	&header = this->_req->getHeaders();
	std::vector<std::string>	index = this->_req->getIndex();
	std::string					path = this->_req->getConfigedPath();
	std::string 				res;

	if(!this->_req->isExistHeader("Path")){
		this->_req->setStateCode(400);
		this->_req->setStateText("Bad Request");
		return false;
	}
	// path = this->_req->getRoot() + header["Path"];
	for (size_t i = 0; i < index.size(); i++)
	{
		if (isExistResource(path, index[i]))
			return true;
	}
	this->_req->setStateCode(404);
	this->_req->setStateText("Not Found");
	return false;
}

bool				RequestInspect::isExistResource(std::string path, std::string index) {
	struct stat	s;

	if(stat(path.c_str(),&s) == 0)
	{
		if(s.st_mode & S_IFDIR)
		{
			if (path[(int)path.length() - 1] != '/')
				path = path + "/";
			path = path + index;
			return (isExistResource(path, ""));
		}
		else if(s.st_mode & S_IFREG)
		{
			if (path.find(".bla") != std::string::npos ||
			path.find(".bad_extension") != std::string::npos)
				std::cout << "need cgi run" << std::endl;
		}
		// _req->_headers["Path"] = path;
		return true;
	}
	return false;
}

bool				RequestInspect::isValidVersion() {
	ParsedRequest::HeaderType &header = _req->getHeaders();

	if (_req->isExistHeader("Version") && header["Version"] == "HTTP/1.1")
		return true;
	this->_req->setStateCode(505);
	this->_req->setStateText("Version Not Supported");
	return false;
}

// bool				RequestInspect::isValidContent() {
// 	std::string method = ;
// 	// post, put without content-length 411, 400
// 	if (_req->_headers["Type"] == ft::methods[POST] || method == ft::methods[PUT]) {
// 		if (_req->isExistHeader("Content-Length")) {
// 			// ignore content-length since transfer-encoding contained
// 			if (_req->isExistHeader("Transfer-Encoding") && _req->_headers["Transfer-Encoding"] != "identity")
// 				return true;
// 			// todo need stoi to check
// 			if (_req->_headers["Content-Length"] == _req->_body.length())
// 				return true;
// 			// bad request
// 			this->_req->setStateCode(400);
// 			this->_req->setStateText(400);
// 			return false;
// 		}
// 		// request should contain content-length
// 		this->_req->setStateCode(411);
// 		this->_req->setStateText(411);
// 		return false;
// 	}
// 	return true;
// }

bool				RequestInspect::isAllowedMethod() {
	ParsedRequest::HeaderType	&header = this->_req->getHeaders();
	std::vector<std::string>	allowed = this->_req->getAllowMethods();
	size_t						i = 0;

	while (i < this->_req->getAllowMethods().size())
	{
		if (header["Type"] == allowed[i] )
			return true;
		i++;
	}
	this->_req->setStateCode(405);
	this->_req->setStateText("Method Not Allowed");
	return false;
}

bool				RequestInspect::isValid() {
	if (!isValidStart())
		return false;
	// if (!isValidContent())
	// 	return false;
	if (!isAllowedMethod())
		return false;
	return true;
}

