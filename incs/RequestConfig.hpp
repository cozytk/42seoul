#ifndef REQUEST_CONFIG_HPP
# define REQUEST_CONFIG_HPP
class RequestConfig;

# include "ParsedRequest.hpp"
# include <array>

/*
** root ✅
** allow_method ✅
** index
** client_max_body_size
** error_page
** extension
** autoindex
** sever_name maybe
*/

class RequestConfig
{
	private:
		ParsedRequest				*_req;
		Config::node				*_serv_node;
		Config::node				*_loc_node;
		std::string					_root;
		std::string					_extension;
		std::vector<std::string>	_index;
		std::vector<std::string>	_allow_methods;

		void			configRoot(Config::node* node_ptr);
		// void			configIndex(Config::node* node_ptr);
		// void			configMaxBody(Config::node* node_ptr);
		// void			configErrorPage(Config::node* node_ptr);
		// void			configAutoIndex(Config::node* node_ptr);
		void			configMethod(Config::node* node_ptr);
		void			applyConfig(Config::node* nodeptr);
	public:
		RequestConfig();
		RequestConfig(ParsedRequest *req);
		RequestConfig(const RequestConfig& copy);
		RequestConfig& operator=(const RequestConfig& obj);
		virtual ~RequestConfig();

		std::string const &				getRoot();

};

/* global operator overload */
std::ostream&	operator<<(std::ostream& out, const RequestConfig& requestConfig);

#endif
