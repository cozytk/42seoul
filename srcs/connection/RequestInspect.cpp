#include "RequestInspect.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

/* static variable code */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

RequestInspect::RequestInspect() {}

RequestInspect::RequestInspect(const RequestInspect& copy):
_req(copy._req)
{}

RequestInspect::RequestInspect(ParsedRequest *req):
_req(req)
{
	Config::node				server_node;
	Config::node				location_node;
	std::string					root;
	int							i = 0;
	ParsedRequest::HeaderType	&header = (*_req).getHeaders();
	std::string					path = header["Path"];
	std::string					config_loc;

/*
** 	default server root
*/
	server_node = *((*this->_req).getConfig());
	if (server_node.size("root") > 0)
		this->_root = (*server_node("root"))[0];
/*
** 	location init
*/
	while (i < server_node.size("location"))
	{
		config_loc = (*server_node("location", i))[0];
		if (path.find(config_loc) == (size_t) 0)
		{
			this->_location = config_loc;
			break;
		}
		i++;
	}
/*
** 	location root
*/
	// i = 0;
	// while (i < node("location"))

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


bool				RequestInspect::isValidStart() {
	if (!isValidType() || !isValidPath() || !isValidVersion())
		return false;
	(*_req).setStateCode(200);
	return true;
}

bool				RequestInspect::isValidType() {
	ParsedRequest::HeaderType &header = (*_req).getHeaders();
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
	if (!(*_req).isExistHeader("Type"))
	{
		(*_req).setStateCode(400);
		return false;
	}
	while (++i < 8)
	{
		if (header["Type"] == methods[i])
			return true;
	}
	// get, head can't be 405
	// todo should check server support method if not return 405
	(*_req).setStateCode(400);
	return false;
}

bool				RequestInspect::isValidPath() {
	struct stat					s;
	std::string 				res;
	std::string					path;
	ParsedRequest::HeaderType	&header = (*_req).getHeaders();
	Config::node				*config = (*_req).getConfig();
		//
	int i = 0;
	std::cout << "configing" << std::endl;
	std::cout << "server size: " << (*config).size("location") << std::endl;
	Config::node node;
	node = (*config);
	std::cout << "get location: " << node.size("location") << std::endl;
	std::vector<std::string> v;
	i = 0;
	while (i < node.size("location"))
	{
		std::cout << i << " th:" << (*node("location", i))[0] << std::endl;
		if ((*node("location", i))[0] == "/")
		{
			std::cout << "root apply" << std::endl;
			v = *(*config)("location", i);
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
	if(!(*_req).isExistHeader("Path")){
		(*_req).setStateCode(400);
		return false;
	}
	path = "." + header["Path"];
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
		(*_req).setStateCode(200);
		// (*_req)._headers["Path"] = path;
		return true;
	}
	(*_req).setStateCode(404);
	return false;
}

// void				RequestInspect::applyRoot() {

// 	header["Path"] = this->_root + path;
// }

bool				RequestInspect::isValidVersion() {
	ParsedRequest::HeaderType &header = (*_req).getHeaders();

	if ((*_req).isExistHeader("Version") && header["Version"] == "HTTP/1.1")
		return true;
	(*_req).setStateCode(505);
	return false;
}

// bool				RequestInspect::isValidContent() {
// 	std::string method = ;
// 	// post, put without content-length 411, 400
// 	(*_req).setStateCode(200);
// 	if ((*_req)._headers["Type"] == ft::methods[POST] || method == ft::methods[PUT]) {
// 		if ((*_req).isExistHeader("Content-Length")) {
// 			// ignore content-length since transfer-encoding contained
// 			if ((*_req).isExistHeader("Transfer-Encoding") && (*_req)._headers["Transfer-Encoding"] != "identity")
// 				return true;
// 			// todo need stoi to check
// 			if ((*_req)._headers["Content-Length"] == (*_req)._body.length())
// 				return true;
// 			// bad request
// 			(*_req).setStateCode(400);
// 			return false;
// 		}
// 		// request should contain content-length
// 		(*_req).setStateCode(411);
// 		return false;
// 	}
// 	return true;
// }

bool				RequestInspect::isAllowedMethod() {
	ParsedRequest::HeaderType &header = (*_req).getHeaders();

	if (header["Path"] == "/" && header["Type"] != "GET") {
		(*_req).setStateCode(405);
		return false;
	}
	return true;
}

bool				RequestInspect::isValid() {
	if (!isValidStart())
		return false;
	// if (!isValidContent())
	// 	return false;
	if (!isAllowedMethod())
		return false;
	(*_req).setStateCode(200);
	return true;
}
