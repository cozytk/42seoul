#include "RequestConfig.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

RequestConfig::RequestConfig() {}
RequestConfig::RequestConfig(ParsedRequest *req):
_req(req)
{
	ParsedRequest::HeaderType	&header = (*_req).getHeaders();
	Config::node				server_node;
	std::string					config_loc;
	int							i = 0;
	size_t						last = 0;

	this->_serv_node = (*this->_req).getConfig();
	this->_loc_node = NULL;
	server_node = *this->_serv_node;
	applyConfig(this->_serv_node);
	// location config apply
	while (i < server_node.size("location"))
	{
		config_loc = (*server_node("location", i))[0];
		last = config_loc.length() - (size_t)1;// if use wildcard, location path should end with "/*"
		// wildcard path
		if (config_loc[last] == '*')
		{
			if (header["Path"].find(config_loc.substr(0, last - 1)) == (size_t) 0)
			{
				this->_loc_node = &server_node("location", i);
				applyConfig(this->_loc_node);
				break;
			}
		}
		// non wildcard path
		else if (header["Path"] == config_loc) {
			this->_loc_node = &server_node("location", i);
			applyConfig(this->_loc_node);
			break;
		}
		// config extension
		else if (config_loc[0] == '.') {
			this->_extension = config_loc.substr(1, config_loc.size() - (size_t)2);
		}
		i++;
	}
	//=
	i = 0;
	while ((size_t)i < this->_allow_methods.size())
	{
		std::cout << this->_allow_methods[i] << std::endl;
		i++;
	}
	//=
}

RequestConfig::RequestConfig(const RequestConfig& copy):
_req(copy._req)
{
}

/* ************************************************************************** */
/* ------------------------------- DESTRUCTOR ------------------------------- */
/* ************************************************************************** */

RequestConfig::~RequestConfig()
{
}

/* ************************************************************************** */
/* -------------------------------- OVERLOAD -------------------------------- */
/* ************************************************************************** */

RequestConfig& RequestConfig::operator=(const RequestConfig& obj)
{
	if (this == &obj)
		return (*this);
	return (*this);
}

/* ************************************************************************** */
/* --------------------------------- GETTER --------------------------------- */
/* ************************************************************************** */

std::string const &				RequestConfig::getRoot() {
	return (this->_root);
}

/* ************************************************************************** */
/* --------------------------------- SETTER --------------------------------- */
/* ************************************************************************** */

/* ************************************************************************** */
/* ------------------------------- EXCEPTION -------------------------------- */
/* ************************************************************************** */

/* ************************************************************************** */
/* ---------------------------- MEMBER FUNCTION ----------------------------- */
/* ************************************************************************** */

void			RequestConfig::configRoot(Config::node* node_ptr)
{
	Config::node				node;

	node = *node_ptr;
	if (node_ptr && node.size("root") > 0)
		this->_root = (*node("root"))[0];
}

void			RequestConfig::configMethod(Config::node* node_ptr)
{
	size_t	i = 0;

	if ((*node_ptr).size("allow_method") > 0)
		this->_allow_methods = *((*node_ptr)("allow_method"));
	else if (this->_allow_methods.empty()) {
		std::string methods[8] = {
			"GET",
			"HEAD",
			"POST",
			"PUT",
			"DELETE",
			"CONNECT",
			"OPTIONS",
			"TRACE"
		};
		std::vector<std::string> tmp(methods, methods + 8);
		this->_allow_methods = tmp;
	}
}

// void			RequestConfig::configIndex(Config::node* node_ptr)
// {
// 	size_t						i = 0;
// 	if ((*node_ptr).size("allow_method") > 0)
// 		this->_allow_methods = *((*node_ptr)("allow_method"));
// 	else if (this->_allow_methods.empty()) {
// 		std::string methods[8] = {
// 			"GET",
// 			"HEAD",
// 			"POST",
// 			"PUT",
// 			"DELETE",
// 			"CONNECT",
// 			"OPTIONS",
// 			"TRACE"
// 		};
// 		std::vector<std::string> tmp(methods, methods + 8);
// 		this->_allow_methods = tmp;
// 	}
// }


void			RequestConfig::applyConfig(Config::node* nodeptr) {
	if (nodeptr)
	{
		configRoot(nodeptr);
		configMethod(nodeptr);
		// configIndex(nodeptr);
		// configMaxBody(nodeptr);
		// configErrorPage(nodeptr);
		// configAutoIndex(nodeptr);
	}
}
