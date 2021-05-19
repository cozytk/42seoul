#include "ServerManager.hpp"

ServerManager::ServerManager() {
}

ServerManager::ServerManager(ServerManager const &other) {
}

ServerManager::~ServerManager() {
}

ServerManager &ServerManager::operator=(ServerManager const &x) {
}

Server *ServerManager::newServer(Config::node *block)
{
	Server *server = new Server;

	server->setPort( ft::atoi( const_cast<char *>((*(*block)("listen", 0))[0].c_str()) ) );
}

void ServerManager::config(std::string const &path) {
	int i = 0;

	_config.file(path);
	while (i < _config("http", 0).size("server")) {
		_servers.push_back(newServer(&_config("http", 0)("server", i)));
		i++;
	}
}

void ServerManager::run() {
}
