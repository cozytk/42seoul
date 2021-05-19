#ifndef SERVERMANAGER
# define SERVERMANAGER

# include <iostream>
# include <vector>
# include "Server.hpp"
# include "config/Config.hpp"

class Server;

class ServerManager {
private:
	Config				_config;
	std::vector<Server>	_servers;

public:
	ServerManager();
	ServerManager(ServerManager const &other);
	virtual ~ServerManager();
	ServerManager &operator=(ServerManager const &other);

	void run();
	void config(std::string const &path);
};
#endif
