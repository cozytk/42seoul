#include "../../incs/Server.hpp"

/* Request */

std::map<int, std::string> make_status ()
{
	std::map<int, std::string> status_list;
	status_list[100] = "Continue";
	status_list[200] = "OK"; status_list[201] = "Created";
	status_list[202] = "Accepted";
	status_list[204] = "No Content";
	status_list[205] = "Reset Content";
	status_list[206] = "Partial Content";
	status_list[299] = "CGI OK";
	status_list[300] = "Multiple Choice";
	status_list[301] = "Moved Permanently";
	status_list[303] = "See Other";
	status_list[305] = "Use Proxy";
	status_list[307] = "Temporary Redirect";
	status_list[400] = "Bad Request";
	status_list[401] = "Unauthorized";
	status_list[403] = "Forbidden";
	status_list[404] = "Not Found";
	status_list[405] = "Method Not Allowed";
	status_list[406] = "Not Acceptable";
	status_list[407] = "Proxy Authentication Required";
	status_list[408] = "Request Timeout";
	status_list[409] = "Conflict";
	status_list[410] = "Gone";
	status_list[411] = "Length Required";
	status_list[412] = "Precondition Failed";
	status_list[413] = "Payload Too Large";
	status_list[414] = "URI Too Long";
	status_list[415] = "Unsupported Media Type";
	status_list[416] = "Requested Range Not Satisfiable";
	status_list[417] = "Expectation Failed";
	status_list[500] = "Internal Server Error";
	status_list[501] = "Not Implemented";
	status_list[503] = "Service Unavailable";
	status_list[504] = "Gateway Timeout";
	status_list[505] = "HTTP Version Not Supported";
	return (status_list);
}

std::map<int, std::string> Server::_status = make_status();

std::map<std::string, std::string> makeMimeType ()
{
	std::map<std::string, std::string> type_map;

	type_map["avi"] = "video/x-msvivdeo";
	type_map["bin"] = "application/octet-stream";
	type_map["bmp"] = "image/bmp";
	type_map["css"] = "text/css";
	type_map["csv"] = "text/csv";
	type_map["doc"] = "application/msword";
	type_map["docx"] = "application/vnd.openxmlformats-officedocument.wordprocessingml.document";
	type_map["gz"] = "application/gzip";
	type_map["gif"] = "image/gif";
	type_map["htm"] = "text/html";
	type_map["html"] = "text/html";
	type_map["ico"] = "image/vnd.microsoft.icon";
	type_map["jepg"] = "image/jepg";
	type_map["jpg"] = "image/jepg";
	type_map["js"] = "text/javascript";
	type_map["json"] = "application/json";
	type_map["mp3"] = "audio/mpeg";
	type_map["mpeg"] = "video/mpeg";
	type_map["png"] = "image/png";
	type_map["pdf"] = "apllication/pdf";
	type_map["php"] = "application/x-httpd-php";
	type_map["ppt"] = "application/vnd.ms-powerpoint";
	type_map["pptx"] = "application/vnd.openxmlformats-officedocument.presentationml.presentation";
	type_map["rar"] = "application/vnd.rar";
	type_map["sh"] = "application/x-sh";
	type_map["svg"] = "image/svg+xml";
	type_map["tar"] = "application/x-tar";
	type_map["tif"] = "image/tiff";
	type_map["txt"] = "text/plain";
	type_map["wav"] = "audio/wav";
	type_map["xls"] = "application/xhtml+xml";
	type_map["xlsx"] = "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
	type_map["zip"] = "application/zip";
	type_map["bad_extension"] = "application/bad";
	type_map["bla"] = "application/42cgi";
	type_map["pouic"] = "application/pouic";
	return (type_map);
}
std::map<std::string, std::string> Server::_mime_types = makeMimeType();

Server::Request::Request() {
	this->_buffer = "";
	this->_response = "";
	this->_length = -1;
	this->_sent = 0;
}

Server::Request::Request(Server::Request const &x) :
	_buffer(x._buffer), _length(x._length), _sent(x._sent) {
}

Server::Request::~Request() {
}

Server::Request &Server::Request::operator=(Server::Request const &x) {
	this->_buffer = x._buffer;
	this->_length = x._length;
	this->_sent = x._sent;
	return (*this);
}

void Server::Request::parseHeader(std::string const &header) {
	int pos;
	int lf;

	pos = 0;
	while ((lf = header.find("\r\n", pos)) != std::string::npos) {
		if (pos != 0)
			_headers.insert(ft::headerPair(std::string(header.begin() + pos, header.begin() + lf)));
		pos = lf + 2;
	}
	_headers.insert(ft::headerPair(std::string(header, pos)));
}

void Server::Request::clear() {
	this->_headers.clear();
	this->_buffer.clear();
	this->_response.clear();
	this->_length = -1;
	this->_sent = 0;
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
	/*
	std::map<std::string, std::string>_config_map = _server_conf->getChildren()

	if (hasKey(server_map, "server_name"))
		m_server_name = server_map["server_name"];
	else
		m_server_name = "noname";
	m_host = server_map["host"];
	m_port = ft::stoi(server_map["port"]);
	m_request_uri_limit_size = ft::stoi(server_map["REQUEST_URI_LIMIT_SIZE"]);
	m_request_header_limit_size = ft::stoi(server_map["REQUEST_HEADER_LIMIT_SIZE"]);
	m_limit_client_body_size = ft::stoi(server_map["LIMIT_CLIENT_BODY_SIZE"]);
	m_default_error_page = ft::getStringFromFile(server_map["DEFAULT_ERROR_PAGE"]);
	 */
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
		std::cout << "[disconnected;]" << std::endl;
		return (ERR_RECV);
	}
	this->_request[socket]->_buffer += buffer;
	if (this->_request[socket]->_length == -1 && this->_request[socket]->_buffer.find("\r\n\r\n") == std::string::npos)
		return (WAIT_RECV);
	if (this->_request[socket]->_length == -1) {
		this->_request[socket]->parseHeader( this->_request[socket]->_buffer.substr(0, this->_request[socket]->_buffer.find("\r\n\r\n")) );
		if (this->_request[socket]->_headers.find("transfer-encoding") != this->_request[socket]->_headers.end() &&
			this->_request[socket]->_headers["transfer-encoding"] == "chunked") {
			this->_request[socket]->_length = -1;
		}
		else {
			this->_request[socket]->_length = 0;
			if (this->_request[socket]->_headers.find("content-length") != this->_request[socket]->_headers.end())
				this->_request[socket]->_length = ft::atoi(const_cast<char *>(this->_request[socket]->_headers["content-length"].c_str()));
		}
	}
	if (this->_request[socket]->_length != -1 &&
	this->_request[socket]->_buffer.substr(this->_request[socket]->_buffer.find("\r\n\r\n") + 4).length() >= this->_request[socket]->_length) {
		ft::trim_space(this->_request[socket]->_buffer);
		std::cout << std::endl << "RECV ▼ (size: " << this->_request[socket]->_length << ")" << std::endl;
		std::cout << "[" << this->_request[socket]->_buffer << "]" << std::endl;
		this->_parsed_req = new ParsedRequest(this->_request[socket]->_buffer, this->_server_conf);
		RequestConfig req_conf(this->_parsed_req);
		RequestInspect inspect(this->_parsed_req);
		inspect.isValid();

		std::cout << "[" << this->_parsed_req->getBody() << "]" << std::endl;
		return (ALL_RECV);
	}
	if (this->_request[socket]->_length == -1 &&
		this->_request[socket]->_headers.find("transfer-encoding") != this->_request[socket]->_headers.end() &&
		this->_request[socket]->_headers["transfer-encoding"] == "chunked" &&
		this->_request[socket]->_buffer.find("\r\n0\r\n") != std::string::npos) {
		ft::trim_space(this->_request[socket]->_buffer);
		std::cout << std::endl << "RECV chunked ▼ (size: " << this->_request[socket]->_length << ")" << std::endl;
		std::cout << "[" << this->_request[socket]->_buffer << "]" << std::endl;
		this->_parsed_req = new ParsedRequest(this->_request[socket]->_buffer, this->_server_conf);
		RequestInspect inspect(this->_parsed_req);
		inspect.isValid();

		std::cout << "[" << this->_parsed_req->getBody() << "]" << std::endl;
		return (ALL_RECV);
	}
	return (WAIT_RECV);
}

int Server::send(int socket) {
	std::string buf;
	int len;
	int buf_size;

	std::string body;
	std::string header;
	std::string response;

	/* tmp */
//  this->_parsed_req->isValid();
	std::string stateCode = ft::to_string(this->_parsed_req->getStateCode());

//  body = "hello world\nSocket: " + ft::to_string(this->_socket) + "\nPort: " + ft::to_string(this->_port) + "\n";

	std::map<std::string, std::string>_header = _parsed_req->getHeaders();
	std::map<std::string, std::string>::iterator it;

	for (it = _header.begin(); it != _header.end(); it++)
		std::cout << "KEY is <" <<  it->first << "> VALUES is <" << it->second << ">" << std::endl;
	std::cout << "KEY is <" <<  it->first << "> VALUES is <" << it->second << ">" << std::endl;
	std::cout << "KEY is <" <<  it->first << "> VALUES is <" << it->second << ">" << std::endl;

	if (this->_parsed_req->getHeaders()["Type"] == "GET") {
//		response = "HTTP/1.1" + stateCode + runGetHead(this->_parsed_req, GET);
		header = "HTTP/1.1 " + stateCode + " NOK\nServer: webserv\nContent-Type: text/plain\nContent-Length: " + ft::to_string(body.length()) + "\n\n";
	}
	if (this->_parsed_req->getHeaders()["Type"] == "POST")
	{
		response = "HTTP/1.1 " + stateCode + " NOK\nContent-Type: text/plain\nContent-Length: " + ft::to_string(body.length()) + "\n\n";

	}
	if (this->_parsed_req->getHeaders()["Type"] == "HEAD") {
//		response = "HTTP/1.1" + stateCode + runGetHead(this->_parsed_req, HEAD);
		header = "HTTP/1.1 " + stateCode + " NOK\nServer: webserv\nContent-Type: text/plain\nContent-Length: " + ft::to_string(body.length()) + "\n\n";
		body = "";
	}


	/* re */
	buf_size = response.length() - this->_request[socket]->_sent < SEND_BUFFER_SIZE ?
		response.length() - this->_request[socket]->_sent : SEND_BUFFER_SIZE;
	buf = std::string(response, this->_request[socket]->_sent, buf_size);
	len = ::send(socket, buf.c_str(), buf.length(), 0);
	if (len == -1)
		throw SendException();
	if (len == 0)
		return (ERR_SEND);

	std::cout << std::endl << "SEND ▼" << std::endl;
	std::cout << "[" << buf << "]" << std::endl;

	this->_request[socket]->_sent += len;
	if (this->_request[socket]->_sent >= response.length()) {
		return (ALL_SEND);
	}
	delete this->_parsed_req;
	return (WAIT_SEND);
}

bool Server::hasKey(std::map<std::string, std::string>_map, std::string key)
{
	return (!_map[key].empty());
}

std::string Server::getHeaderValue(ParsedRequest *request, std::string key)
{
	return (request->getHeaders()[key]);
}

time_t Server::getLastModifiedHeader(std::string path)
{
	struct stat buf;
	ft::memset(&buf, 0, sizeof(struct stat));
	stat(path.c_str(), &buf);
	return (buf.st_mtimespec.tv_sec);
}

std::string Server::runGetHead(ParsedRequest *request, bool method)
{
	std::map<std::string, std::string>_header = request->getHeaders();
	std::map<std::string, std::string>::iterator it;

	for (it = _header.begin(); it != _header.end(); it++)
		std::cout << "KEY is <" <<  it->first << "> VALUES is <" << it->second << ">" << std::endl;
		std::cout << "KEY is <" <<  it->first << "> VALUES is <" << it->second << ">" << std::endl;
		std::cout << "KEY is <" <<  it->first << "> VALUES is <" << it->second << ">" << std::endl;

//	for (auto it = _server_conf->getChildren().begin(); it != _server_conf->getChildren().end(); it++)
//		std::cout << "[" << it->first << "]" << std::endl;



	std::string path = getHeaderValue(request, "Path");
	std::string body;
	std::vector<std::string> headers(1, path);
//	headers_t headers(1, getMimeTypeHeader(path));

	try {
		body = fileToString(path, request->getMaxBody());
	} catch (std::overflow_error& e) {
		return (response400(request, 413));
	}
	if (headers[0].empty())
		return (response400(request, 415));
	headers.push_back(setLastModifiedHeader());
//	headers.push_back(reinterpret_cast<const char *>(getLastModifiedHeader(path)));
	if (method == HEAD)
		headers.push_back("content-length:" + ft::to_string(int(body.size())));
	return (response200(request, 200, headers, body));
}

std::string Server::response200(ParsedRequest *request, int status, std::vector<std::string> headers, std::string body)
{
	std::string ret;
	headers.push_back(setLastModifiedHeader());
	headers.push_back(setServerName());
/* todo cgi response
	if (status == CGI_SUCCESS_CODE)
		createCGIResponse(status, headers, body);
	*/

//	todo when Trasfer-Encoding, skip

	headers.push_back(setContentLength(body));
	if (!body.empty())
		headers.push_back(setContentLanguage());
	if (getHeaderValue(request, "Type") == "HEAD")
		body = "";
	for (std::vector<std::string>::iterator it = headers.begin(); it != headers.end(); it++)
		ret += *it;
	return (ret);
	 // todo response generate, header factoring


}

std::string Server::response400(ParsedRequest *request, int status)
{
	std::string ret;
	std::vector<std::string> headers;
	std::string body;

	body = "";
	headers.push_back(setLastModifiedHeader());
	headers.push_back(setServerName());
/* todo cgi response */

	body = "errorpage";
	body.replace(body.find("#ERROR_CODE"), 11, ft::to_string(status));
	body.replace(body.find("#ERROR_CODE"), 11, ft::to_string(status));
	body.replace(body.find("#ERROR_DESCRIPTION"), 18, Server::_status[status]);
	body.replace(body.find("#ERROR_DESCRIPTION"), 18, Server::_status[status]);
	body.replace(body.find("#PORT"), 5, ft::to_string(_port));
	 //todo Transfer-Encoding

	headers.push_back(setContentLanguage());
	headers.push_back("Connection:close");
	for (std::vector<std::string>::iterator it = headers.begin(); it != headers.end(); it++)
		ret += *it;
	return (ret);
    // todo response generate, header factoring
}


std::string Server::fileToString(std::string path, int limit)
{
	char buf[1024];
	int fd;
	ssize_t cnt = 0;
	std::string str;

	if ((fd = open(path.c_str(), O_RDONLY)) == -1)
		throw (std::invalid_argument("Invalid : " + path));
	while ((cnt = read(fd, buf, 1024)) > 0)
	{
		str.append(buf, cnt);
		if (limit != -1 && str.size() > limit)
			throw (std::overflow_error("Overflow : " + path));
	}
	close(fd);
	return (str);
}


std::string Server::setLastModifiedHeader()
{
	char buff[1024];
	struct tm *t;
	time_t now = time(NULL);

	t = localtime(&now);
	strftime(buff, 1024, "%a, %d %b %Y %X GMT", t);
	return ("Last-Modified:" + std::string(buff));
}

std::string Server::setServerName()
{
	return ("Server: ");
//	eturn ("Server: " + getServerName());
}

std::string Server::setContentLength(const std::string& body)
{
	return ("Content-Length:" + ft::to_string(body.size()));
}

std::string Server::setContentLanguage()
{
	return ("Content-Language:ko-KR");
}