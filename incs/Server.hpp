#ifndef SERVER_HPP
# define SERVER_HPP

# include <webserv.hpp>

# include "ServerManager.hpp"

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

	private:
		/* member */
		std::string		_buffer;
		int				_sent;

		bool			_chunked;

		/* function */
		void clear();
	};

	/* member */
	ServerManager				*_manager;

	sockaddr_in					_addr;
	int							_socket;
	int							_port;

	std::vector<int>			_readable;
	std::vector<int>			_writable;

	std::map<int, Buffer>		_buffer;

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

	void send();
	void receive();
	void accept();

	void run();

};
#endif
