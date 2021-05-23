#include "Server.hpp"

/* Request */
Server::Request::Request() {
	this->_header = "";
	this->_body = "";
	this->_length = -1;
	this->_sent = 0;
}

Server::Request::Request(Server::Request const &x) :
	_header(x._header), _body(x._body), _length(x._length) {
}

Server::Request::~Request() {
}

Server::Request &Server::Request::operator=(Server::Request const &x) {
	this->_header = x._header;
	this->_body = x._body;
	this->_length = x._length;
	return (*this);
}

void Server::Request::parseHeader() {
	int pos;
	int lf;

	pos = 0;
	while ((lf = _header.find("\r\n", pos)) != std::string::npos)
	{
		if (pos != 0)
			_headers.insert(ft::headerPair(std::string(_header.begin() + pos, _header.begin() + lf)));
		pos = lf + 2;
	}
	_headers.insert(ft::headerPair(std::string(_header, pos)));
}


/* Server */
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
Server::Server() {
}

Server::Server(Server const &x) {
}

Server::~Server() {
	std::multimap<int, Request *>::iterator it;
	std::multimap<int, Request *>::iterator n_it;

	it = this->_request.begin();
	while (it != this->_request.end()) {
		n_it = it;
		++n_it;
		delete it->second;
		this->_request.erase(it);
		it = n_it;
	}
}

Server &Server::operator=(Server const &x) {
	return (*this);
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
}

void Server::run() {
	if (listen(this->_socket, 512) == -1)
		throw ListenException();
	std::cout << this->_socket << " is being run (port: " << this->_port << ")" << std::endl;
}

int Server::accept() {
	int socket;

	if ((socket = ::accept(this->_socket, 0, 0)) == -1)
		throw AcceptException();
	fcntl(socket, F_SETFL, O_NONBLOCK);
	this->_request.insert(std::make_pair<int, Request *>(socket, new Request));
	return (socket);
}

int Server::recv(int socket) {
	char buf[RECV_BUFFER_SIZE + 1];
	std::string buffer = "";
	int len;

	len = ::recv(socket, buf, RECV_BUFFER_SIZE, 0);
	buf[len] = 0;
	buffer += buf;
	if (len == -1)
		throw ReceiveException();
	if (len == 0)
	{
		std::cout << "disconnected;" << std::endl;
		close(socket);
		return (ERR_RECV);
	}
	
	if (this->_request[socket]->_length == -1) {
		this->_request[socket]->_header = buffer.substr(0, buffer.find("\r\n\r\n"));
		this->_request[socket]->_body = buffer.substr(buffer.find("\r\n\r\n") + 4);
		this->_request[socket]->parseHeader();
		this->_request[socket]->_length = 0;
		if (this->_request[socket]->_headers.find("content-length") != this->_request[socket]->_headers.end())
			this->_request[socket]->_length = ft::atoi(const_cast<char *>(this->_request[socket]->_headers["content-length"].c_str()));
	}
	else {
		this->_request[socket]->_body += buffer;	
	}
	if (this->_request[socket]->_body.length() >= this->_request[socket]->_length)
		return (ALL_RECV);
	return (WAIT_RECV);
}

int Server::send(int socket) {
	std::string buf;
	int len;

	/* tmp */
	std::string body = "hello world\nSocket: " + ft::to_string(this->_socket) + "\nPort: " + ft::to_string(this->_port) + "\n";
	std::string header = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: " + ft::to_string(body.length()) + "\n\n";

	std::string response = header + body;

	/* re */
	buf = std::string(response, this->_request[socket]->_sent, SEND_BUFFER_SIZE);
	len = ::send(socket, buf.c_str(), buf.length(), 0);
	if (len == -1)
		throw SendException();
	if (len == 0)
		return (ERR_SEND);
	this->_request[socket]->_sent += len;
	if (this->_request[socket]->_sent >= response.length())
	{
		this->_request[socket]->_sent = 0;
		this->_request.erase(socket);
		close(socket);
		return (ALL_SEND);
	}
	return (WAIT_SEND);
}

/*
	std::string body = "hello world\nSocket: " + std::to_string(this->_socket) + "\nPort: " + std::to_string(this->_port) + "\n";
	std::string header = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: " + std::to_string(body.length()) + "\n\n";

	write(socket, (header + body).c_str(), (header + body).length());
 */
