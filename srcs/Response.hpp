//#ifndef RESPONSE_HPP
//# define RESPONSE_HPP
//
//# include <string>
//# include <iostream>
//
//# define GET 1
//# define HEAD 0
//
//#include "../incs/webserv.hpp"
//#include "connection/Request.hpp"
//
//class Response
//{
//	public:
//		static std::map<int, std::string> status;
//	private:
//		std::map<std::string, std::string> _headers;
//		std::string _serverName;
//		std::string _errorPage;
//		int _port;
//		int _limitClientBodySize = 20000000;
//	public:
//		Response();
//		Response(const std::string& /* parameter */, ...);
//		Response(const Response& copy);
//		Response& operator=(const Response& obj);
//		virtual ~Response();
//
//		/* declare member function */
//
//		void sortMethod(Connection& connection, const Request& request);
//		void response100(Connection& connection, int status, headers_t headers, std::string body);
//		void response200(Connection& connection, int status, headers_t headers, std::string body);
//		void response300(Connection& connection, int status, headers_t headers, std::string body);
//		void response400(Connection& connection, int status, headers_t headers, std::string body);
//		void response500(Connection& connection, int status, headers_t headers, std::string body);
//		std::string fileToString(std::string path, int limit);
//		static std::string getMethod() { return ("");}
//		std::string getMimeTypeHeader(std::string path) const;
//		static time_t getLastModifiedHeader(const std::string& path);
//		std::string getServerName() const;
//		std::string setLastModified();
//		std::string setServerName();
//		std::string setContentLength(const std::string &body);
//		std::string setContentLanguage();
//};
//
///* global operator overload */
//std::ostream&	operator<<(std::ostream& out, const Response& response);
//
//#endif
