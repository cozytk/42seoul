#ifndef SERVER_HPP
# define SERVER_HPP

# include <webserv.hpp>

# include "ServerManager.hpp"

class ServerManager;

class Server {
	friend class ServerManager;

private:
	class Request {
	friend class Server;

	private:
		/* request */
		std::map<std::string, std::string> _headers;
		std::string _header;
		std::string _body;

		int _length;

		int _sent;

	public:
		Request();
		Request(Request const &x);
		~Request();

		Request &operator=(Request const &x);

		void parseHeader();
	};

	std::map<int, Request *>	_request;
	sockaddr_in					_addr;
	int							_socket;
	int							_port;
	//std::vector<Location>		_locations;

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

};
#endif
