#include "../../incs/ServerManager.hpp"

/* signal */
bool ServerManager::alive = true;

void interrupt(int i) {
	ft::Log(Error, "Interrupt");
	ServerManager::alive = false;
}

/* exception */
const char *ServerManager::ArgvException::what() const throw() {
	return ("ServerManagerException: Wrong arguments");
}

const char *ServerManager::NoServerMemberException::what() const throw() {
	return ("ServerManagerException: Server is not declaration");
}

const char *ServerManager::NetFunctionException::what() const throw() {
	return ("ServerManagerException: Failed to excute built-in function");
}

/* coplien */
ServerManager::ServerManager() {
	signal(SIGINT, &interrupt);
}

ServerManager::ServerManager(ServerManager const &x) {
}

ServerManager::~ServerManager() {
	this->close();
	for (int i = 0; i < this->_servers.size(); i++)
		delete this->_servers[i];
}

ServerManager &ServerManager::operator=(ServerManager const &x) {
	return (*this);
}

/* private */
Server *ServerManager::createServer(Config::node *block) {
	Server *server = new Server(this);
	/* bind */
	server->_server_conf = block;
	server->_port = ft::atoi( const_cast<char *>((*(*block)("listen", 0))[0].c_str()) );
	server->bind();
	/* reg */
	ft::fd_set(server->_socket, &this->_fds.read);
	if (this->_max_fd < server->_socket)
		this->_max_fd = server->_socket;
	/* ret */
	return (server);
}

/* public */
void ServerManager::config(int argc, char **argv) {
	std::string path;
	Server *tmp;
	int i = 0;

	/* check */
	if (argc == 1) {
		path = DEFAULT_CONF;
		ft::Log(Warning, "using default config file (" + std::string(DEFAULT_CONF) + ")");
	}
	else if (argc == 2)
		path = argv[1];
	else
		throw ArgvException();
	/* init server */
	this->_max_fd = 0;
	ft::fd_zero(&this->_fds.read);
	ft::fd_zero(&this->_fds.write);
	ft::fd_zero(&this->_fds.except);
	this->_fds.timeout.tv_sec = 0;
	this->_fds.timeout.tv_usec = 0;
	/* init config */
	_config.file(path);
	if (static_cast<int>(_config("http", 0).size("server")) == 0)
		throw NoServerMemberException();
	while (i < _config("http", 0).size("server"))
		_servers.push_back(createServer(&_config("http", 0)("server", i++)));
}

void ServerManager::accept(int socket, Server *server) {
	struct sockaddr_in	client_addr;
	socklen_t			client_addrlen;
	int					client_socket;

	client_addrlen = sizeof(client_addr);
	if ((client_socket = ::accept(socket, (struct sockaddr *)&client_addr, &client_addrlen)) == -1)
		return ;
	ft::fd_set(client_socket, &this->_fds.read);
	this->_map[client_socket] = server;
	this->_map[client_socket]->_buffer[client_socket].clear();
	this->_readable.push_back(client_socket);
	fcntl(client_socket, F_SETFL, O_NONBLOCK);
	if (client_socket > this->_max_fd)
		this->_max_fd = client_socket;
}

void ServerManager::recv(int socket, std::vector<int>::iterator &next_socket) {
	char	buf[RECV_BUFFER_SIZE + 1];
	int		bytes;

	if ((bytes = ::read(socket, buf, RECV_BUFFER_SIZE)) == -1)
		return ;
	else if(bytes == 0) {
		next_socket = _readable.erase(std::find(_readable.begin(), _readable.end(), socket));
		::close(socket);
		ft::fd_clr(socket, &this->_fds.read);
		return ;
	}
	buf[bytes] = 0;
	if (this->_map[socket]->recv(socket, buf) == ALL_RECV) {
		_writable.push_back(socket);
		ft::fd_set(socket, &this->_fds.write);
	}
}

void ServerManager::send(int socket, std::vector<int>::iterator &next_socket) {
	if (this->_map[socket]->send(socket) == ALL_RECV) {
		this->_map[socket]->_buffer[socket].clear();
		next_socket = _writable.erase(std::find(_writable.begin(), _writable.end(), socket));
		ft::fd_clr(socket, &this->_fds.write);
	}
}

void ServerManager::run() {
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	next_it;
	int							fd_on;

	/* listen */
	for (std::vector<Server *>::iterator it = _servers.begin(); it != _servers.end(); it++)
		(*it)->listen();
	/* run */
	while(ServerManager::alive)
	{
		this->_fds_out = this->_fds;
		fd_on = select(this->_max_fd + 1, &this->_fds_out.read, &this->_fds_out.write, NULL, &this->_fds_out.timeout);
		if (fd_on == 0)
			continue;
		for (it = _writable.begin(); it != _writable.end(); it = next_it) {
			next_it = it + 1;
			if (ft::fd_isset(*it, &this->_fds_out.write))
				send(*it, next_it);
		}
		for (it = _readable.begin(); it != _readable.end(); it = next_it) {
			next_it = it + 1;
			if (ft::fd_isset(*it, &this->_fds_out.read))
				recv(*it, next_it);
		}
		for (std::vector<Server *>::iterator it = _servers.begin(); it != _servers.end(); it++) {
			if (ft::fd_isset((*it)->_socket, &this->_fds_out.read))
				accept((*it)->_socket, *it);
		}
	}
}

void ServerManager::close() {
	for (int i = 0; i < this->_max_fd; i++)
		::close(i);
}
