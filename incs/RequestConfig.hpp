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

		void			configErrorPage(Config::node* node_ptr);
		void			configMethod(Config::node* node_ptr);
		void			applyConfig(Config::node* node_ptr);
		void			replacePath(std::string path, std::string config_loc, Config::node * server_node, size_t last);
	public:
		RequestConfig();
		RequestConfig(ParsedRequest *req);
		RequestConfig(const RequestConfig& copy);
		RequestConfig& operator=(const RequestConfig& obj);
		virtual ~RequestConfig();

};

/* global operator overload */
std::ostream&	operator<<(std::ostream& out, const RequestConfig& requestConfig);

#endif
