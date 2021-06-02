#ifndef SERVER_HPP
# define SERVER_HPP

# include <webserv.hpp>

# include "ServerManager.hpp"
# include "ParsedRequest.hpp"
# include "RequestInspect.hpp"

#define GET 0
#define HEAD 1

class ServerManager;

class Server {
	friend class ServerManager;

private:
	class Request {
	friend class ServerManager;
	friend class Server;

	private:
		std::map<std::string, std::string> _headers;
		std::string _buffer;
		std::string _response;
		int _length;
		int _sent;

	public:
		Request();
		Request(Request const &x);
		~Request();

		Request &operator=(Request const &x);

		void parseHeader(std::string const &header);

		void clear();
	};

	std::map<int, Request *>	_request;
	sockaddr_in					_addr;
	int							_socket;
	int							_port;
	Config::node *				_server_conf;
	ParsedRequest *				_parsed_req;
	static std::map<std::string, std::string> _mime_types;
	static std::map<int, std::string> _status;
	size_t                      _uriLimitSize;
	size_t                      __headerLimitSize;
	size_t                      _limitClientBodySize;
	std::string                 _defaultErrorPage;

public:
	/* exception */
	typedef std::vector<std::string> headers_t;
		class CreateException : public std::exception {
		virtual const char *what() const throw();
	};

	class ListenException : public std::exception {
		virtual const char *what() const throw();
	};

	class AcceptException : public std::exception {
		virtual const char *what() const throw();
	};

	class ReceiveException : public std::exception {
		virtual const char *what() const throw();
	};

	class SendException : public std::exception {
		virtual const char *what() const throw();
	};

	/* coplien */
	Server();
	Server(Server const &other);
	virtual ~Server();
	Server &operator=(Server const &other);

	int getPort();

	void socketBind();
	void run();

	int accept();
	int recv(int socket);
	int send(int socket);

	std::string runGet(ParsedRequest *request);
	std::string runPost(ParsedRequest *request);
	std::string runDelete(ParsedRequest *request);
	time_t getLastModifiedHeader(std::string path);
	std::string getServerHeader(ParsedRequest *request);
	std::string getDateHeader(ParsedRequest *request);
	std::string getContentTypeHeader(ParsedRequest *request);
	std::string getContentLengthHeader(ParsedRequest *request);
	std::string getLastModifiedHeader(ParsedRequest *request);
	std::string getConnectionHeader(ParsedRequest *request);
	std::string isOK(int state);
};
#endif
