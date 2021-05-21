#ifndef SERVER_HPP
# define SERVER_HPP

# include <webserv.hpp>

# include "ServerManager.hpp"

class ServerManager;

class Server {
	friend class ServerManager;

private:
	sockaddr_in				_addr;
	int						_socket;
	int						_port;
	//std::vector<Location>	_locations;

public:	
	/* exception */
	class CreateException : public std::exception {
		virtual const char *what() const throw();
	};

	class ListenException : public std::exception {
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

};
#endif
