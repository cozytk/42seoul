#include "../../incs/Server.hpp"

/* Buffer */
/* coplien */
Server::Buffer::Buffer() {
}

Server::Buffer::Buffer(Buffer const &x) {
}

Server::Buffer::~Buffer() {
}

Server::Buffer &Server::Buffer::operator=(Buffer const &x) {
	return (*this);
}


/* exception */
const char *Server::CreateException::what() const throw() {
	return ("ServerException: Failed to create server");
}

const char *Server::ListenException::what() const throw() {
	return ("ServerException: Failed to open server");
}

const char *Server::AcceptException::what() const throw() {
	return ("ServerException: Failed to accept connection");
}

const char *Server::ReceiveException::what() const throw() {
	return ("ServerException: Failed to receive packet");
}

const char *Server::SendException::what() const throw() {
	return ("ServerException: Failed to send packet");
}

/* coplien */
Server::Server(ServerManager *manager) :
_manager(manager) {
}

Server::Server(Server const &x) {
}

Server::~Server() {
}

Server &Server::operator=(Server const &x) {
	return (*this);
}

void Server::bind() {
	if ((this->_socket = ::socket(AF_INET, SOCK_STREAM, 0)) == -1)
		throw CreateException();
	ft::memset((char *)&this->_addr, 0, sizeof(this->_addr));
	this->_addr.sin_family = AF_INET;
	this->_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	this->_addr.sin_port = htons(this->_port);
	if (::bind(this->_socket, (sockaddr *)&this->_addr, sizeof(this->_addr)) == -1)
		throw CreateException();
}

void Server::listen() {
	if (::listen(this->_socket, 512) == -1)
		throw ListenException();
	fcntl(this->_socket, F_SETFL, O_NONBLOCK);
	ft::Log(Log, "Server: PORT " + ft::to_string(this->_port) + " is listening");
}

void Server::send() {
	int sockfd;

	std::vector<int>::iterator it = _writable.begin();
	std::vector<int>::iterator n_it;
	while (it != _writable.end())
	{
		sockfd = *it;
		n_it = it + 1;
		if (ft::fd_isset(sockfd, &this->_manager->_fds_out.write))
		{
			std::string a = "HTTP/1.1 200 OK\nContent-Length: 1\n\na\n\n";
			write(sockfd, a.c_str(), a.length());
			n_it = _writable.erase(std::find(_writable.begin(), _writable.end(), sockfd));
			ft::fd_clr(sockfd, &this->_manager->_fds.write);
		}
		it = n_it;
	}
}

void Server::readPacket(int socket, std::vector<int>::iterator &socket_next) {
	char	buf[RECV_BUFFER_SIZE + 1];
	int		bytes;

	if ((bytes = ::read(socket, buf, RECV_BUFFER_SIZE)) == -1) {
		if (errno != EAGAIN) {
			std::cout << socket<< " -1" << std::endl;
			ft::fd_clrs(socket, &this->_manager->_fds);
			::close(socket);
			if (std::find(_writable.begin(), _writable.end(), socket) != _writable.end())
				_writable.erase(std::find(_writable.begin(), _writable.end(), socket));
			socket_next = _readable.erase(std::find(_readable.begin(), _readable.end(), socket));
		}
		return ;
	}
	else if(bytes == 0) {
		std::cout << socket<< " 0" << std::endl;
		ft::fd_clrs(socket, &this->_manager->_fds);
		::close(socket);
		if (std::find(_writable.begin(), _writable.end(), socket) != _writable.end())
			_writable.erase(std::find(_writable.begin(), _writable.end(), socket));
		socket_next = _readable.erase(std::find(_readable.begin(), _readable.end(), socket));
		return ;
	}
	buf[bytes] = 0;
	std::cout << socket << " " << buf << std::endl;

	_writable.push_back(socket);
	ft::fd_set(socket, &this->_manager->_fds.write);
}

void Server::receive() {
	std::vector<int>::iterator	socket;
	std::vector<int>::iterator	socket_next;

	socket = _readable.begin();
	while (socket != _readable.end())
	{
		socket_next = socket + 1;
		if (ft::fd_isset(*socket, &this->_manager->_fds_out.read))
			readPacket(*socket, socket_next);
		socket = socket_next;
	}
}

void Server::accept() {
	socklen_t			addrlen;
	struct sockaddr_in	client_addr;
	int					client_socket;

	if (ft::fd_isset(this->_socket, &this->_manager->_fds_out.read))
	{
		addrlen = sizeof(client_addr);
		client_socket = ::accept(this->_socket, (struct sockaddr *)&client_addr, &addrlen);
		fcntl(client_socket, F_SETFL, O_NONBLOCK);
		ft::fd_set(client_socket, &this->_manager->_fds.read);
		_readable.push_back(client_socket);
		if (client_socket > this->_manager->_max_fd)
			this->_manager->_max_fd = client_socket;
	}
}

void Server::run() {
	send();
	receive();
	accept();
}
