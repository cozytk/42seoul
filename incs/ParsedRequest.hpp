#ifndef PARSED_REQUEST_HPP
# define PARSED_REQUEST_HPP
class ParsedRequest;

# include <string>
# include <map>
# include <iostream>
# include <vector>
# include <utility>
# include <cstring>
# include <sys/stat.h>
# include <unistd.h>
# include "Config.hpp"
# include "RequestConfig.hpp"
# include "WebServerConstant.hpp"

class ParsedRequest
{
	friend class RequestConfig;
	public:
	typedef	std::map<std::string, std::string> HeaderType;
	typedef std::map<std::string, std::string>	ErrorPage;
	private:
		HeaderType					_headers;
		std::string					_body;
		std::string					_stateText;
		bool						_isChunked;
		int							_stateCode;
		Config::node *				_config;
		std::string					_root;
		std::string					_configed_path;
		std::string					_extension;
		std::string					_server_name;
		std::string					_id;
		std::string					_pw;
		int							_max_body;
		bool						_autoindex;
		std::vector<std::string>	_index;
		std::vector<std::string>	_allow_methods;
		ErrorPage					_error_page;

		void			parseBody(std::string const &body);
		void			parseHead(std::string const &request);

	public:
		ParsedRequest();
		ParsedRequest(std::string const &request, Config::node *config);
		ParsedRequest(const ParsedRequest& copy);
		ParsedRequest& operator=(const ParsedRequest& obj);
		virtual ~ParsedRequest();

		int								getStateCode();
		HeaderType						&getHeaders();
		Config::node *					getConfig();
		std::string						getBody();
		std::string						getConfigedPath();
		std::string						getStateText();
		std::string						getId();
		std::string						getPw();
		std::string const &				getRoot();
		std::string const &				getExtension();
		std::string const &				getServerName();
		int const &						getMaxBody();
		bool const &					getAutoIndex();
		std::vector<std::string>		getIndex();
		std::vector<std::string>		getAllowMethods();
		ErrorPage						getErrorPage();

		void							setStateCode(int state);
		void							setStateText(std::string text);

		bool							isChunked();
		bool							isExistHeader(std::string in);
};
//Accept-Charsets
//Accept-Language
//Allow
//Authorization
//Content-Language
//Content-Length
//Content-Location
//Content-Type
//Date
//Host
//Last-Modified
//Location
//Referer
//Retry-After
//Server
//Transfer-Encoding
//User-Agent
//WWW-Authenticate

// GET
// HEAD
// POST
// PUT
// DELETE
// CONNECT
// OPTIONS
// TRACE

#endif