#include "RequestConfig.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

RequestConfig::RequestConfig() {}
RequestConfig::RequestConfig(ParsedRequest *req):
_req(req), _loc_node(NULL)
{
	ParsedRequest::HeaderType	&header = req->getHeaders();
	Config::node				server_node;
	std::string					config_loc;
	size_t						i = 0;
	size_t						last = 0;

	this->_serv_node = (*this->_req).getConfig();
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
			}
		}
		// non wildcard path
		else if (header["Path"] == config_loc) {
			this->_loc_node = &server_node("location", i);
			applyConfig(this->_loc_node);
		}
		// config extension
		else if (config_loc[0] == '.')
			this->_req->_extension = config_loc.substr(1, config_loc.size() - (size_t)1);
		i++;
	}
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

/* ************************************************************************** */
/* --------------------------------- SETTER --------------------------------- */
/* ************************************************************************** */

/* ************************************************************************** */
/* ------------------------------- EXCEPTION -------------------------------- */
/* ************************************************************************** */

/* ************************************************************************** */
/* ---------------------------- MEMBER FUNCTION ----------------------------- */
/* ************************************************************************** */

void			RequestConfig::configMethod(Config::node* node_ptr)
{
	if (node_ptr->size("allow_method") > 0)
		this->_req->_allow_methods = *((*node_ptr)("allow_method"));
	else if (this->_req->_allow_methods.empty()) {
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
		this->_req->_allow_methods = tmp;
	}
}

void			RequestConfig::configErrorPage(Config::node* node_ptr)
{
	Config::node	node;
	std::string		error_code;
	std::string		error_page_path;
	size_t			i = 0;

	node = *node_ptr;
	if (node.size("error_page") > 0)
	{
		while (i < (*node("error_page")).size())
		{
			error_code = (*node("error_page"))[i];
			if (node.size(error_code) > 0)
				error_page_path = (*node(error_code))[0];
			else
				error_page_path = this->_req->_root + "error.html";
			this->_req->_error_page[error_code] = error_page_path;
			i++;
		}
	}
}

void			RequestConfig::applyConfig(Config::node* node_ptr) {
	Config::node				node;

	if (node_ptr)
	{
		node = *node_ptr;
		if (node.size("root") > 0)
			this->_req->_root = (*node("root"))[0];
		if (node.size("index") > 0)
			this->_req->_index = *node("index");
		configMethod(node_ptr);
		if (node.size("client_max_body_size") > 0)
			this->_req->_max_body = ft::atoi(const_cast<char *>((*node("client_max_body_size"))[0].c_str()));
		if (node.size("autoindex") > 0 && (*node("autoindex"))[0] == "on")
			this->_req->_autoindex = true;
		if (node.size("server_name") > 0)
			this->_req->_server_name = (*node("server_name"))[0];
		configErrorPage(node_ptr);
	}
}
