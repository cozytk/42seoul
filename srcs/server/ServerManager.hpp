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
	std::map<int, Server *>	_readable;
	std::map<int, Server *>	_writable;

	ft::fds fds;
	int inspect_range;

	Server *newServer(Config::node *block);

public:	
	/* static */
	static bool alive;

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

	/* signal */
	void serverClose();
};

#endif
