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
	this->_buffer.reserve(100000000);
}

CGI::CGI(CGI const &x) {
}

CGI::~CGI() {
	close(_stdin);
	close(_stdout);
}

CGI &CGI::operator=(CGI const &x) {
	return (*this);
}

void CGI::setEnvs(ParsedRequest *request) {
	envs["AUTH_TYPE"] = "BASIC";
	envs["CONTENT_LENGTH"] = request->getHeaders()["Content-Length"];
	envs["CONTENT_TYPE"] = request->getHeaders()["Content-Type"];

	envs["GATEWAY_INTERFACE"] = "CGI/1.1";

	envs["PATH_INFO"] = request->getHeaders()["Path"];
	envs["PATH_TRANSLATED"] = request->getConfigedPath();
	envs["QUERY_STRING"] = "";

	envs["REMOTE_ADDR"] = "127.0.0.1";
	envs["REMOTE_IDENT"] = "unknown";
	envs["REMOTE_USER"] = "unknown";

	envs["REQUEST_METHOD"] = request->getHeaders()["Type"];
	envs["REQUEST_URI"] = request->getHeaders()["Path"];

	envs["SCRIPT_NAME"] = "127.0.0.1";

	envs["SERVER_NAME"] = request->getServerName();
	envs["SERVER_PORT"] = (*(*request->getConfig())("listen", 0))[0];
	envs["SERVER_PROTOCOL"] = "HTTP/1.1";
	envs["SERVER_SOFTWARE"] = "webserv/1.0";
	envs["HTTP_X_SECRET_HEADER_FOR_TEST"] = request->getHeaders()["X-Secret-Header-For-Test"];
}

char **CGI::getEnvs(ParsedRequest *request) {
	std::map<std::string, std::string>::iterator it;
	char **ret;
	std::string buf;
	int i = 0;

	setEnvs(request);
	ret = new char*[envs.size() + 1];
	for (it = envs.begin(); it != envs.end(); it++) {
		buf = it->first + "=" + it->second;
		ret[i] = new char[buf.length() + 1];
		ft::strlcpy(ret[i++], const_cast<char *>(buf.c_str()), buf.length() + 1);
	}
	ret[i] = NULL;
	return (ret);
}

void CGI::execute(ParsedRequest *request)
{
	/* example */
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
	write(fd_in, request->getBody().c_str(), request->getBody().length());
	lseek(fd_in, 0, SEEK_SET);
	argv = getEnvs(request);
	if ((pid = fork()) == -1)
		throw ForkException();
	if (pid == 0) {
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		execve(request->getCGIPass().c_str(), NULL, argv);
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
