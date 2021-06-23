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

/* function */
void Server::Buffer::clear() {
	this->_checked = false;
	this->_buffer.clear();
	this->_length = 0;
	this->_sent = 0;
	this->_chunked = false;
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

int Server::recv(int socket, char *buf) {
	this->_buffer[socket]._buffer += buf;

	if (this->_buffer[socket]._buffer.find("\r\n\r\n") == std::string::npos)
		return (WAIT_RECV);
	if (!this->_buffer[socket]._checked) {
		this->_buffer[socket]._length = ft::getLength(this->_buffer[socket]._buffer);
		this->_buffer[socket]._chunked = ft::getChunked(this->_buffer[socket]._buffer);
		this->_buffer[socket]._checked = true;
		if (!this->_buffer[socket]._chunked && this->_buffer[socket]._length != -1)
			this->_buffer[socket]._buffer.reserve(this->_buffer[socket]._buffer.find("\r\n\r\n") + this->_buffer[socket]._length + 10);
	}
	if (!this->_buffer[socket]._chunked &&
		static_cast<int>(this->_buffer[socket]._buffer.substr(this->_buffer[socket]._buffer.find("\r\n\r\n") + 4).length()) >= this->_buffer[socket]._length) {
		ft::trim_space(this->_buffer[socket]._buffer);
		this->process(socket, _cgi);
		return (ALL_RECV);
	}
	else if (this->_buffer[socket]._chunked && this->_buffer[socket]._buffer.find("\r\n0\r\n") != std::string::npos) {
		ft::trim_space(this->_buffer[socket]._buffer);
		ft::trim_chunked(this->_buffer[socket]._buffer);
		this->process(socket, _cgi);
		return (ALL_RECV);
	}
	return (WAIT_RECV);
}

int Server::send(int socket) {
	int				len;
	std::string		buf;
	int				buf_size;

	buf_size = this->_buffer[socket]._buffer.length() - this->_buffer[socket]._sent < SEND_BUFFER_SIZE ?
	           this->_buffer[socket]._buffer.length() - this->_buffer[socket]._sent : SEND_BUFFER_SIZE;
	buf = std::string(this->_buffer[socket]._buffer, this->_buffer[socket]._sent, buf_size);
	if ((len = write(socket, buf.c_str(), buf.length())) == -1)
		return (WAIT_SEND);
	this->_buffer[socket]._sent += len;
    if (this->_buffer[socket]._sent >= this->_buffer[socket]._buffer.length())
		return (ALL_SEND);
	return (WAIT_SEND);
}

void Server::process(int socket, CGI &cgi) {
	// std::cout << this->_buffer[socket]._buffer << std::endl;
	this->_parsed_request = new ParsedRequest(this->_buffer[socket]._buffer, this->_server_conf);
	RequestConfig	req_conf(this->_parsed_request);
	RequestInspect	insperct(this->_parsed_request);
	insperct.isValid();
	ParsedRequest::ErrorPage error = this->_parsed_request->getErrorPage();
	ParsedRequest::ErrorPage::iterator it = error.begin();
	Response _response(this->_parsed_request, this);

	this->_buffer[socket]._buffer = _response.getResponse(_auto_index, _cgi, this->_buffer[socket]._buffer);
    std::cout << this->_buffer[socket]._buffer << std::endl;
	delete this->_parsed_request;
	// std::cout << this->_buffer[socket]._buffer << std::endl;
}
