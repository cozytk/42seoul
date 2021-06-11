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
}

ServerManager &ServerManager::operator=(ServerManager const &x) {
	return (*this);
}

/* private */
Server *ServerManager::createServer(Config::node *block) {
	Server *server = new Server(this);
	/* bind */
	server->_port = ft::atoi( const_cast<char *>((*(*block)("listen", 0))[0].c_str()) );
	server->bind();
	/* register */
	ft::fd_set(server->_socket, &this->_fds.read);
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
	/* init config */
	_config.file(path);
	if (static_cast<int>(_config("http", 0).size("server")) == 0)
		throw NoServerMemberException();
	while (i < _config("http", 0).size("server"))
		_servers.push_back(createServer(&_config("http", 0)("server", i++)));
}

void ServerManager::run() {
	int		pos;

	/* timeout */
	this->_fds.timeout.tv_sec = 0;
	this->_fds.timeout.tv_usec = 0;
	/* listen */
	for (std::vector<Server *>::iterator server = this->_servers.begin(); server != this->_servers.end(); server++)
		(*server)->listen();
	/* run */
	while (ServerManager::alive) {
		this->_fds_out = this->_fds;
		if ((pos = ::select(this->_max_fd + 1, &this->_fds_out.read, &this->_fds_out.write, 0, &this->_fds_out.timeout)) == -1) {

			std::cout << strerror(errno) << std::endl;
			throw NetFunctionException();
		}
		if (pos == 0)
			continue;
		for (std::vector<Server *>::iterator server = this->_servers.begin(); server != this->_servers.end(); server++) {
			(*server)->run();
		}
	}
}

void ServerManager::close() {
	for (int i = 0; i < this->_max_fd; i++)
		::close(i);
}
