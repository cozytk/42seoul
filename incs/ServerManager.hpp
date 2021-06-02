#ifndef SERVERMANAGER_HPP
# define SERVERMANAGER_HPP

# include <webserv.hpp>

# include "Server.hpp"
# include "Config.hpp"

class Server;

class ServerManager {
private:
	/* member */
	Config					_config;
	std::map<int, Server *>	_servers;
	std::map<int, Server *>	_readable;
	std::map<int, Server *>	_writable;

	ft::fds fds;
	int inspect_range;

	/* func */
	Server *newServer(Config::node *block);

	void write(struct ft::fds &fds_loop);
	void read(struct ft::fds &fds_loop);
	void accept(struct ft::fds &fds_loop);

public:
	/* static */
	static bool alive;

	/* exception */
	class ArgvException : public std::exception {
		virtual const char *what() const throw();
	};

	class NoServerMemberException : public std::exception {
		virtual const char *what() const throw();
	};

	class NetFunctionException : public std::exception {
		virtual const char *what() const throw();
	};

	/* coplien */
	ServerManager();
	ServerManager(ServerManager const &x);
	virtual ~ServerManager();

	ServerManager &operator=(ServerManager const &x);

	void config(int argc, char **argv);
	void run();

	/* signal */
	void serverClose();
};

#endif
