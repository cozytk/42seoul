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

bool				RequestInspect::isValidType() {
	ParsedRequest::HeaderType &header = _req->getHeaders();
	size_t i = -1;

	if (!_req->isExistHeader("Type"))
	{
		this->_req->setStateCode(400);
		this->_req->setStateText("Bad Request");
		return false;
	}
	if (isAllowedMethod())
		return true;
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
	size_t		extension_dot = path.find(".");

	if (extension_dot != std::string::npos &&
	path.substr(extension_dot) == this->_req->getExtension())
		return true;
	if(stat(path.c_str(),&s) == 0)
	{
		if(s.st_mode & S_IFDIR)
		{
			if (path[(int)path.length() - 1] != '/')
				path = path + "/";
			if (this->_req->getResponseAny() > 0)
			{
				if (this->_req->getResponseAny() < this->_req->getBody().length())
				{
					this->_req->setStateCode(400);
					return false;
				}
				return true;
			}
			if (!this->_req->getAutoIndex())
			{
				path = path + index;
				if (!isExistResource(path, ""))
					return (false);
			}
			this->_req->setConfigedPath(path);
		}
		else if(s.st_mode & S_IFREG)
		{
			if (this->_req->getAutoIndex())
				this->_req->setAutoIndex(false);
			if (path.find(".bla") != std::string::npos ||
			path.find(".bad_extension") != std::string::npos ||
			path.find(".yahong") != std::string::npos )
				this->_req->setCGIBool(true);
		}
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
	// get, head can't be 405 but tester approve accessing '/' only get,
	// on the ohter hand webserv work differently.
	// if allow_method is configed, allow_method inspect will precede.
	// so get, head can response with 405.
	this->_req->setStateCode(405);
	this->_req->setStateText("Method Not Allowed");
	return false;
}

bool				RequestInspect::isAuthorized() {
	ParsedRequest::HeaderType	&header = this->_req->getHeaders();
	std::string 				id = this->_req->getId();
	std::string 				pw = this->_req->getPw();
	std::string 				auth;

	// need auth
	if (pw != "")
	{
		if (header.find("Authorization") != header.end())
		{
			auth = header["Authorization"];
			if (id + ":" + pw == ft::base64::decode(auth.substr(6, auth.length())))
				return true;
		}
		this->_req->setStateCode(401);
		this->_req->setStateText("Unauthorized");
		return false;
	}
	return true;
}

bool				RequestInspect::isValidSize() {
	if (this->_req->getMaxBody() >= 0 && this->_req->getMaxBody() < this->_req->getBody().length())
	{
		this->_req->setStateCode(413);
		this->_req->setStateText("Payload Too Large");
		return false;
	}
	return true;
}

bool				RequestInspect::isValid() {
	if (!isValidType())
		return false;
	if (!isValidSize())
		return false;
	if (!isValidVersion())
		return false;
	if (!isValidPath())
		return false;
	if (!isAuthorized())
		return false;
	return true;
}

