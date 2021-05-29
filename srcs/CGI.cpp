#include "CGI.hpp"

/* exception */
const char *CGI::FileIOException::what() const throw() {
	return ("CGIException: error in file IO");
}

/* exception */
const char *CGI::ForkException::what() const throw() {
	return ("CGIException: fork() returned -1");
}

/* coplien */
CGI::CGI() {
	this->_stdin = dup(STDIN_FILENO);
	this->_stdout = dup(STDOUT_FILENO);
	setEnvs();
}

CGI::CGI(CGI const &x) {
	setEnvs();
}

CGI::~CGI() {
	close(_stdin);
	close(_stdout);
}

CGI &CGI::operator=(CGI const &x) {
	return (*this);
}

void CGI::setEnvs() {
	envs["AUTH_TYPE"] = "";
	envs["CONTENT_LENGTH"] = "";
	envs["CONTENT_TYPE"] = "";

	envs["GATEWAY_INTERFACE"] = "CGI/1.1";

	envs["PATH_INFO"] = "";
	envs["PATH_TRANSLATED"] = "";
	envs["QUERY_STRING"] = "";

	envs["REMOTE_ADDR"] = "";
	envs["REMOTE_IDENT"] = "";
	envs["REMOTE_USER"] = "";

	envs["REQUEST_METHOD"] = "";
	envs["REQUEST_URI"] = "";

	envs["SCRIPT_NAME"] = "";

	envs["SERVER_NAME"] = "";
	envs["SERVER_PORT"] = "";
	envs["SERVER_PROTOCOL"] = "HTTP/1.1";
	envs["SERVER_SOFTWARE"] = "webserv/1.0";
}

char **CGI::getEnvs() {
	std::map<std::string, std::string>::iterator it;
	char **ret = new char*[envs.size() + 1];
	std::string buf;
	int i = 0;
	
	for (it = envs.begin(); it != envs.end(); it++) {
		buf = it->first + "=" + it->second;
		ret[i] = new char[buf.length() + 1];
		ft::strlcpy(ret[i++], const_cast<char *>(buf.c_str()), buf.length() + 1);
	}
	ret[i] = NULL;
	return (ret);
}

void CGI::execute() {

	/* example */
	std::string body = "name=webserv&key=val";

	std::string &buffer = this->_buffer;
	char buf[CGI_BUFFER_SIZE + 1];
	char **argv;
	int len;
	int pid;
	int fd_in;
	int fd_out;

	buffer = "";
	if (((fd_in = open("/tmp/webserv.cache.in", O_RDWR | O_CREAT | O_TRUNC, 0777)) == -1) ||
	((fd_out = open("/tmp/webserv.cache.out", O_RDWR | O_CREAT | O_TRUNC, 0777)) == -1))
		throw FileIOException();
	write(fd_in, body.c_str(), body.length());
	lseek(fd_in, 0, SEEK_SET);
	argv = getEnvs();
	if ((pid = fork()) == -1)
		throw ForkException();
	if (pid == 0) {
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		execve("./test/cgi_tester", NULL, argv);
		std::cout << "CGI Error: 500 Internal" << std::endl;
		exit(0);
	}
	waitpid(pid, NULL, 0);
	lseek(fd_out, 0, SEEK_SET);
	while ((len = read(fd_out, buf, CGI_BUFFER_SIZE)) > 0) {
		buf[len] = 0;
		buffer += buf;
	}
	if (len == -1)
		throw FileIOException();
	buf[len] = 0;
	buffer += buf;
	dup2(_stdin, STDIN_FILENO);
	dup2(_stdout, STDOUT_FILENO);
	pid = 0;
	while (argv[pid]) {
		delete[] argv[pid];
		pid++;
	}
	delete[] argv;
	close(fd_in);
	close(fd_out);
}

std::string &CGI::getBuffer() {
	return (this->_buffer);
}
