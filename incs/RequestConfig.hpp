#ifndef REQUEST_CONFIG_HPP
# define REQUEST_CONFIG_HPP
class RequestConfig;

# include "ParsedRequest.hpp"
# include <array>

/*
** root ✅
** allow_method ✅
** index ✅
** client_max_body_size ✅
** error_page ✅
** extension ⏸
** autoindex ✅
** sever_name ✅
*/

class RequestConfig
{
	public:
		typedef std::map<std::string, std::string>	ErrorPage;
	private:
		ParsedRequest				*_req;
		Config::node				*_serv_node;
		Config::node				*_loc_node;
		std::string					_root;
		std::string					_extension;
		std::string					_server_name;
		int							_max_body;
		bool						_autoindex;
		std::vector<std::string>	_index;
		std::vector<std::string>	_allow_methods;
		ErrorPage					_error_page;

		void			configErrorPage(Config::node* node_ptr);
		void			configMethod(Config::node* node_ptr);
		void			applyConfig(Config::node* node_ptr);
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
