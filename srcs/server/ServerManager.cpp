#include "ServerManager.hpp"

ServerManager::ServerManager() {
}

ServerManager::ServerManager(ServerManager const &other) {
}

ServerManager::~ServerManager() {
}

ServerManager &ServerManager::operator=(ServerManager const &x) {
}

Server *ServerManager::newServer(Config::node *block) {
	Server *server = new Server;

	server->_port = ft::atoi( const_cast<char *>((*(*block)("listen", 0))[0].c_str()) );

	server->socketBind();

	return (server);
}

void ServerManager::config(std::string const &path) {
	Server *tmp;
	int i = 0;

	_config.file(path);
	while (i < _config("http", 0).size("server")) {
		tmp = newServer(&_config("http", 0)("server", i));
		_servers.insert(std::pair<int, Server *>(tmp->_port, tmp));
		i++;
	}
}

void ServerManager::run() {
	std::map<int, Server *>::iterator server = this->_servers.begin();
	
	for (; server != this->_servers.end(); server++)
	{
		(server->second)->run();
	}
}


