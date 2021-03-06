#ifndef SERVERMANAGER_HPP
# define SERVERMANAGER_HPP

# include <webserv.hpp>
# include "Server.hpp"
# include "Config.hpp"

class Server;

class ServerManager {
	friend class Server;

private:
	/* member */
	Config						_config;

	std::vector<Server *>		_servers;
	std::vector<int>			_readable;
	std::vector<int>			_writable;

	std::map<int, Server *>		_map;

	ft::fds						_fds;
	ft::fds						_fds_out;
	int							_max_fd;

	/* func */
	Server *createServer(Config::node *block);

	void accept(int socket, Server *server);
	void recv(int socket, std::vector<int>::iterator &socket_next);
	void send(int socket, std::vector<int>::iterator &socket_next);

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
	void close();
};

#endif
