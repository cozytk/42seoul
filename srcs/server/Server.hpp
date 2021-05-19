#ifndef SERVER_HPP
# define SERVER_HPP

# include <webserv.hpp>

# include "ServerManager.hpp"

class ServerManager;

class Server {
private:
	int						_port;
	//std::vector<Location>	_locations;

public:	
	friend class ServerManager;

	Server();
	Server(Server const &other);
	virtual ~Server();
	Server&operator=(Server const &other);

	void setPort(int _port);
	int getPort();

	void run();

};
#endif
