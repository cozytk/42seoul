#ifndef SERVER_HPP
# define SERVER_HPP

# include <webserv.hpp>

# include "ServerManager.hpp"
# include "ParsedRequest.hpp"
# include "RequestInspect.hpp"
# include "RequestConfig.hpp"
# include "Response.hpp"
# include "AutoIndex.hpp"
# include "CGI.hpp"

class ServerManager;

class Server {
	friend class ServerManager;

private:
	class Buffer {
		friend class Server;

	public:
		/* coplien */
		Buffer();
		Buffer(Buffer const &x);
		~Buffer();

		Buffer &operator=(Buffer const &x);

		/* function */
		void clear();

	private:
		/* member */
		bool			_checked;

		std::string		_buffer;
		int				_length;

		int				_sent;

		bool			_chunked;
	};

	/* member */
	ServerManager				*_manager;

	sockaddr_in					_addr;
	int							_socket;
	int							_port;

	std::map<int, Buffer>		_buffer;

	Config::node				*_server_conf;
	ParsedRequest				*_parsed_request;
	AutoIndex                   _auto_index;
	CGI                         _cgi;
	/* function */
	void readPacket(int socket, std::vector<int>::iterator &socket_next);

	/* coplien */
	Server();

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
	Server(ServerManager *manager);
	Server(Server const &other);
	virtual ~Server();
	Server &operator=(Server const &other);

	void bind();
	void listen();

	int recv(int socket, char *buf);
	int send(int socket);

	void process(int socket, CGI &cgi);
};
#endif
