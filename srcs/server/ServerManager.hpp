#ifndef SERVERMANAGER_HPP
# define SERVERMANAGER_HPP

# include <webserv.hpp>

# include "Server.hpp"
# include "../config/Config.hpp"

class Server;

class ServerManager {
public:
	/* class, struct */
	struct fds {
		fd_set read;
		fd_set write;
		fd_set except;
	};

private:
	Config					_config;
	std::map<int, Server *>	_servers;

	struct fds fds;
	int inspect_range;

	Server *newServer(Config::node *block);

public:	
	/* exception */
	class NetFunctionException : public std::exception {
		virtual const char *what() const throw();
	};

	/* coplien */
	ServerManager();
	ServerManager(ServerManager const &x);
	virtual ~ServerManager();

	ServerManager &operator=(ServerManager const &x);

	void config(std::string const &path);

	void run();
};

#endif
