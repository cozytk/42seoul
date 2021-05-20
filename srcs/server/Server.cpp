#include "Server.hpp"

/* exception */

const char *Server::CreateException::what() const throw() {
	return ("ServerException: Failed to create server");
}

/* coplien */
Server::Server() {
}

Server::Server(Server const &x) {
}

Server::~Server() {
}

Server &Server::operator=(Server const &x) {
}

int Server::getPort() {
	return (this->_port);
}

void Server::socketBind() {
	if ((this->_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		throw CreateException();
	ft::memset((char *)&this->_addr, 0, sizeof(this->_addr));
	this->_addr.sin_family = AF_INET;
	this->_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	this->_addr.sin_port = htons(this->_port);
	if (bind(this->_socket, (sockaddr *)&this->_addr, sizeof(this->_addr)) == -1)
		throw CreateException();
	if (listen(this->_socket, 512) == -1)
		throw CreateException();
}

void Server::run() {
}
