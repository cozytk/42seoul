#include "ServerManager.hpp"

/* exception */
const char *ServerManager::NetFunctionException::what() const throw() {
	return ("ServerManagerException: Failed to excute built-in function");
}

/* coplien */
ServerManager::ServerManager() {
}

ServerManager::ServerManager(ServerManager const &other) {
}

ServerManager::~ServerManager() {
}

ServerManager &ServerManager::operator=(ServerManager const &x) {
	return (*this);
}

Server *ServerManager::newServer(Config::node *block) {
	Server *server = new Server;
	/* bind */
	server->_port = ft::atoi( const_cast<char *>((*(*block)("listen", 0))[0].c_str()) );
	server->socketBind();
	/* register */
	ft::fd_set(server->_socket, &this->fds.read);
	ft::fd_set(server->_socket, &this->fds.write);
	ft::fd_set(server->_socket, &this->fds.except);
	this->inspect_range = server->_socket;
	/* ret */
	return (server);
}

void ServerManager::config(std::string const &path) {
	Server *tmp;
	int i = 0;

	/* init server */
	this->inspect_range = 0;
	ft::fd_zero(&this->fds.read);
	ft::fd_zero(&this->fds.write);
	ft::fd_zero(&this->fds.except);
	/* init config */
	_config.file(path);
	while (i < _config("http", 0).size("server")) {
		tmp = newServer(&_config("http", 0)("server", i));
		_servers.insert(std::pair<int, Server *>(tmp->_socket, tmp));
		i++;
	}
}

void ServerManager::run() {
	std::map<int, Server *>::iterator server = this->_servers.begin();
	int select_ret;
	struct fds fds_loop;
	timeval timeout;
	
	/* init */
	timeout.tv_sec = 5;
	timeout.tv_usec = 0;
	/* run */
	for (; server != this->_servers.end(); server++)
	{
		(server->second)->run();
	}
	while (1)
	{
		fds_loop = this->fds;
		if ((select_ret = select(this->inspect_range + 1, &fds_loop.read, &fds_loop.write, &fds_loop.except, &timeout)) == -1)
			throw NetFunctionException();
		if (select_ret == 0)
		{
			std::cout << "time out" << std::endl;
			continue;
		}

	}
}
