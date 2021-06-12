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
	
	int listen_fd, listen_fd1, listen_fd2, client_fd;
	socklen_t addrlen;
	int fd_num;
	int maxfd = 0;
	int sockfd;
	int readn;
	int i= 0;
	char buf[10000];
	fd_set readfds, writefds, allfds_r, allfds_w;
	std::vector<int> _server;
	std::vector<int> _readable;
	std::vector<int> _writable;
	maxfd = 0;

	struct sockaddr_in server_addr, client_addr;

	/* listen */
	FD_ZERO(&readfds);
	FD_ZERO(&writefds);
	for (std::vector<Server *>::iterator it = _servers.begin(); it != _servers.end(); it++) {
		FD_SET((*it)->_socket, &readfds);
		if (maxfd < (*it)->_socket)
			maxfd = (*it)->_socket;
	}

	for (std::vector<Server *>::iterator it = _servers.begin(); it != _servers.end(); it++)
		(*it)->listen();

	while(ServerManager::alive)
	{
		allfds_r = readfds;
		allfds_w = writefds;
		printf("Select Wait %d\n", maxfd);
		fd_num = select(maxfd + 1 , &allfds_r, &allfds_w,
					  (fd_set *)0, NULL);

		std::vector<int>::iterator it = _writable.begin();
		std::vector<int>::iterator n_it;
		while (it != _writable.end())
		{
			sockfd = *it;
			n_it = it + 1;
			if (FD_ISSET(sockfd, &allfds_w))
			{
				std::string a = "HTTP/1.1 200 OK\nContent-Length: 1\n\na\n\n";
				write(sockfd, a.c_str(), a.length());
				n_it = _writable.erase(std::find(_writable.begin(), _writable.end(), sockfd));
				FD_CLR(sockfd, &writefds);
			}
			it = n_it;
		}

		it = _readable.begin();
		while (it != _readable.end())
		{
			sockfd = *it;
			n_it = it + 1;
			if (FD_ISSET(sockfd, &allfds_r))
			{
				if ((readn = read(sockfd, buf, 10000-1)) == -1)
				{
					if (errno != EAGAIN) {
					::close(sockfd);
					n_it = _readable.erase(std::find(_readable.begin(), _readable.end(), sockfd));
					std::cout << "err " << sockfd << std::endl;
					}
				}
				else if(readn == 0)
				{
					printf("close %d\n", sockfd);
					n_it = _readable.erase(std::find(_readable.begin(), _readable.end(), sockfd));
					::close(sockfd);
					FD_CLR(sockfd, &readfds);
				}
				else {
					_writable.push_back(sockfd);
					FD_SET(sockfd, &writefds);
				}
			}
			it = n_it;
		}

		for (std::vector<Server *>::iterator it = _servers.begin(); it != _servers.end(); it++) {
			int listen_fd;

			listen_fd = (*it)->_socket;

			if (FD_ISSET(listen_fd, &allfds_r))
			{
				addrlen = sizeof(client_addr);
				if ((client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addrlen)) == -1) {
					if (errno != EAGAIN) {
						std::cout << "sys err" << std::endl;
					}
					continue;
				}

				FD_SET(client_fd,&readfds);
				_readable.push_back(client_fd);
				fcntl(client_fd, F_SETFL, O_NONBLOCK);

				if (client_fd > maxfd)
					maxfd = client_fd;
				std::cout << "Accept OK " << client_fd << std::endl;
			}
		}

	}

}

void ServerManager::close() {
	for (int i = 0; i < this->_max_fd; i++)
		::close(i);
}
