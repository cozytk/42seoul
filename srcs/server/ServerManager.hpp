#ifndef SERVERMANAGER_HPP
# define SERVERMANAGER_HPP

# include <webserv.hpp>

# include "Server.hpp"
# include "../config/Config.hpp"

class Server;

class ServerManager {
private:
	Config					_config;
	std::map<int, Server *>	_servers;

	Server *newServer(Config::node *block);

public:

	ServerManager();
	ServerManager(ServerManager const &x);
	virtual ~ServerManager();

	ServerManager &operator=(ServerManager const &x);

	void config(std::string const &path);

	void bind();
	void run();

};

#endif
