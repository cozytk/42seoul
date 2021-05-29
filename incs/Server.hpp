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
		typedef std::vector<std::string> headers_t;
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

public:
	/* exception */
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

	void runGetHead(ParsedRequest *request, bool method);
	void response200(Connection& connection, int status, headers_t headers, std::string body);
	void response400(Connection& connection, int status);
};
#endif
