#include "../../incs/ServerManager.hpp"

/* signal */
bool ServerManager::alive = true;

void interrupt(int i) {
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

ServerManager::ServerManager(ServerManager const &other) {
}

ServerManager::~ServerManager() {
	std::multimap<int, Server *>::iterator it;
	std::multimap<int, Server *>::iterator n_it;

	it = this->_servers.begin();
	while (it != this->_servers.end()) {
		n_it = it;
		++n_it;
		delete it->second;
		this->_servers.erase(it);
		it = n_it;
	}
}

ServerManager &ServerManager::operator=(ServerManager const &x) {
	return (*this);
}

Server *ServerManager::newServer(Config::node *block) {
	Server *server = new Server;
	/* bind */
	server->_port = ft::atoi( const_cast<char *>((*(*block)("listen", 0))[0].c_str()) );
	server->_server_conf = block;
	server->socketBind();
	/* register */
	ft::fd_set(server->_socket, &this->fds.read);
	ft::fd_set(server->_socket, &this->fds.except);
	this->inspect_range = server->_socket;
	/* ret */
	return (server);
}

void ServerManager::write(struct ft::fds &fds_loop) {
	std::map<int, Server *>::iterator server;
	std::map<int, Server *>::iterator n_server;
	int tmp;

	server = this->_writable.begin();
	while (server != this->_writable.end())
	{
		n_server = server;
		n_server++;
		if (ft::fd_isset(server->first, &fds_loop.write))
		{
			tmp = (server->second)->send(server->first);
			if (tmp == ALL_SEND) {
				tmp = server->first;
				delete (server->second)->_request[tmp];
				(server->second)->_request.erase(tmp);
				(server->second)->_request.insert(std::make_pair<int, Server::Request *>(tmp, new Server::Request));
				ft::fd_clr(server->first, &this->fds.write);
				this->_writable.erase(server->first);
			}
			else if (tmp == ERR_SEND) {
				ft::fd_clrs(server->first, &this->fds);
				this->_writable.erase(server->first);
				this->_readable.erase(server->first);
			}
		}
		server = n_server;
	}
}

void ServerManager::read(struct ft::fds &fds_loop) {
	std::map<int, Server *>::iterator server;
	std::map<int, Server *>::iterator n_server;
	int tmp;

	server = this->_readable.begin();
	while (server != this->_readable.end())
	{
		n_server = server;
		n_server++;
		if (ft::fd_isset(server->first, &fds_loop.read))
		{
			tmp = (server->second)->recv(server->first);
			if (tmp == ALL_RECV) {
				this->_writable.insert(std::pair<int, Server *>(server->first, server->second));
				ft::fd_set(server->first, &this->fds.write);
			}
			else if (tmp == ERR_RECV) {
				(server->second)->_request.erase(server->first);
				ft::fd_clrs(server->first, &this->fds);	
				::close(server->first);
				this->_readable.erase(server->first);
			}
		}
		server = n_server;
	}
}

void ServerManager::accept(struct ft::fds &fds_loop) {
	std::map<int, Server *>::iterator server;
	std::map<int, Server *>::iterator n_server;
	int tmp;

	for (server = this->_servers.begin(); server != this->_servers.end(); server++)
	{
		if (ft::fd_isset(server->first, &fds_loop.read))
		{
			tmp = (server->second)->accept();
			this->_readable.insert(std::pair<int, Server *>(tmp, server->second));
			ft::fd_set(tmp, &this->fds.read);
			this->inspect_range = tmp > this->inspect_range ? tmp : this->inspect_range;
		}
	}
}

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
	this->inspect_range = 0;
	ft::fd_zero(&this->fds.read);
	ft::fd_zero(&this->fds.write);
	ft::fd_zero(&this->fds.except);
	/* init config */
	_config.file(path);
	if (static_cast<int>(_config("http", 0).size("server")) == 0)
		throw NoServerMemberException();
	while (i < _config("http", 0).size("server")) {
		tmp = newServer(&_config("http", 0)("server", i));
		_servers.insert(std::pair<int, Server *>(tmp->_socket, tmp));
		i++;
	}
}

void ServerManager::run() {
	int select_ret;
	struct ft::fds fds_loop;

	/* init */
	this->fds.timeout.tv_sec = 4;
	this->fds.timeout.tv_usec = 0;
	/* listen */
	for (std::map<int, Server *>::iterator server = this->_servers.begin(); server != this->_servers.end(); server++)
		(server->second)->run();
	/* run */
	while (ServerManager::alive) {
		fds_loop = this->fds;
		if ((select_ret = select(this->inspect_range + 1, &fds_loop.read, &fds_loop.write, NULL, &fds_loop.timeout)) == -1) {
			if (ServerManager::alive)
				throw NetFunctionException();
			break ;
		}
		if (select_ret == 0) {
			ft::Log(Log, "Time out");
			continue;
		}
		write(fds_loop);
		read(fds_loop);
		accept(fds_loop);
	}
}

/* signal */
void ServerManager::serverClose() {
	ft::Log(Error, "Interrupt");
	std::map<int, Server *>::iterator server;

	/*
	for (server = this->_servers.begin(); server != this->_servers.end(); server++)
		::close(server->first);
	for (server = this->_readable.begin(); server != this->_readable.end(); server++)
		::close(server->first);
	for (server = this->_writable.begin(); server != this->_writable.end(); server++)
		::close(server->first);
	*/
	for (int i = 0; i < this->inspect_range + 1; i++)
		::close(i);
}
