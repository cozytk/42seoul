#include "Server.hpp"

Server::Server() {
}

Server::Server(Server const &x) {
}

Server::~Server() {
}

Server &Server::operator=(Server const &x) {
}

void Server::setPort(int _port) {
	this->_port = _port;
}

int Server::getPort() {
	return (this->_port);
}

void Server::run() {
}
