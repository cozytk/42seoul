#include "../../incs/Server.hpp"

#include "AutoIndex.hpp"

/* Request */

std::map<int, std::string> make_status ()
{
	std::map<int, std::string> status_list;
	status_list[100] = "Continue";
	status_list[200] = "OK";
	status_list[201] = "Created";
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
	ft::Log(Log, "Server: PORT " + ft::to_string(this->_port) + " is listening");
}

int Server::accept() {
	int socket;

	if ((socket = ::accept(this->_socket, 0, 0)) == -1)
		throw AcceptException();
	fcntl(socket, F_SETFL, O_NONBLOCK);
	this->_request.insert(std::make_pair<int, Request *>(socket, new Request));
	ft::Log(Log, "Server: PORT " + ft::to_string(this->_port) + " => ACCEPT");
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
		ft::Log(Log, "Server: PORT " + ft::to_string(this->_port) + " => DISCONNECTED by socket " + ft::to_string(socket));
		return (ERR_RECV);
	}
	ft::Log(Log, "Server: PORT " + ft::to_string(this->_port) + " => RECEIVE => " + ft::to_string(buffer.length()) + " bytes");
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
		// std::cout << "[" << this->_request[socket]->_buffer << "]" << std::endl;
		this->_parsed_req = new ParsedRequest(this->_request[socket]->_buffer, this->_server_conf);
		RequestInspect inspect(this->_parsed_req);
		RequestConfig req_conf(this->_parsed_req);
		inspect.isValid();

		// std::cout << "[" << this->_parsed_req->getBody() << "]" << std::endl;

		return (ALL_RECV);
	}
	return (WAIT_RECV);
}

int Server::send(int socket) {
	std::string buf;
	int len;
	int buf_size;

	std::string response;
	ParsedRequest *parsed_req = this->_parsed_req;

	std::string header;
	std::string body;
  //this->_parsed_req->isValid();
	std::string stateCode = ft::to_string(this->_parsed_req->getStateCode());
	std::string stateText = this->_parsed_req->getStateText();

  body = "hello world\nSocket: " + ft::to_string(this->_socket) + "\nPort: " + ft::to_string(this->_port) + "\n";

	// if (this->_parsed_req->getHeaders()["Type"] == "GET") {
	// 	header = "HTTP/1.1 " + stateCode + " " + stateText +"\nServer: webserv\nContent-Type: text/plain\nContent-Length: " + ft::to_string(body.length()) + "\n\n";
	// 	// header = "HTTP/1.1 401 Unauthorized\nWWW-Authenticate: Basic\nServer: webserv\nContent-Type: text/plain\nContent-Length: " + ft::to_string(body.length()) + "\n\n";
	// }
	// if (this->_parsed_req->getHeaders()["Type"] == "POST")
	// {
	// 	header = "HTTP/1.1 " + stateCode + " " + stateText +"\nContent-Type: text/plain\nContent-Length: " + ft::to_string(body.length()) + "\n\n";

	// }
	// if (this->_parsed_req->getHeaders()["Type"] == "HEAD") {
	// 	header = "HTTP/1.1 " + stateCode + " " + stateText +"\nServer: webserv\nContent-Type: text/plain\nContent-Length: " + ft::to_string(body.length()) + "\n\n";
	// 	body = "";
	// }
		header = "HTTP/1.1 " + stateCode + " " + stateText +"\nServer: webserv\nContent-Type: text/plain\nContent-Length: " + ft::to_string(body.length()) + "\n\n";
	if (this->_parsed_req->getHeaders()["Type"] == "PUT") {
		header = "HTTP/1.1 201 " + stateText +"\nServer: webserv\nContent-Type: text/plain\nContent-Length: " + ft::to_string(body.length()) + "\n\n";
		body = "";
		for (size_t i = 0; i < (size_t)1000; i++)
		{
			body += "e";
		}
		body += '0';
	}
	response = header + body;

	buf_size = response.length() - this->_request[socket]->_sent < SEND_BUFFER_SIZE ?
		response.length() - this->_request[socket]->_sent : SEND_BUFFER_SIZE;
	buf = std::string(response, this->_request[socket]->_sent, buf_size);
	len = ::send(socket, buf.c_str(), buf.length(), 0);
	if (len == -1)
		throw SendException();
	if (len == 0)
		return (ERR_SEND);
	ft::Log(Log, "Server: PORT " + ft::to_string(this->_port) + " => SEND => " + ft::to_string(len) + " bytes");

	// std::cout << std::endl << "SEND ▼" << std::endl;
	// std::cout << "[" << buf << "]" << std::endl;

	this->_request[socket]->_sent += len;
	if (this->_request[socket]->_sent >= response.length()) {
		return (ALL_SEND);
	}
	delete this->_parsed_req;
	return (WAIT_SEND);
}

std::string Server::runGet(ParsedRequest *request)
{
	std::vector<std::string> headers;
	std::string ret;

	request->setStateCode(200);
	headers.push_back(getServerHeader(request));
	headers.push_back(getDateHeader(request));
	headers.push_back(getContentTypeHeader(request));
	headers.push_back(getContentLengthHeader(request));
	headers.push_back(getLastModifiedHeader(request));
	headers.push_back(getConnectionHeader(request));
	for (std::vector<std::string>::iterator it = headers.begin(); it != headers.end(); it++)
	{
		erase_white_space(*it);
		ret += *it + "\r\n";
	}
	ret += "\r\n";
	ret += request->getBody() + "\r\n";
	return (ret);
}

std::string Server::runPost(ParsedRequest *request)
{
	std::vector<std::string> headers;
	std::string ret;

	if (request->getBody().length() == 0)
		return (runGet(request));
	request->setStateCode(400);
	headers.push_back(getServerHeader(request));
	headers.push_back(getDateHeader(request));
	headers.push_back(getContentTypeHeader(request));
	headers.push_back(getContentLengthHeader(request));
	headers.push_back(getLastModifiedHeader(request));
	headers.push_back(getConnectionHeader(request));
	for (std::vector<std::string>::iterator it = headers.begin(); it != headers.end(); it++)
	{
		erase_white_space(*it);
		ret += *it + "\r\n";
	}
	ret += "\r\n";
	ret += request->getBody() + "\r\n";
	return (ret);
}

std::string Server::runDelete(ParsedRequest *request)
{
	std::vector<std::string> headers;
	std::string ret;

	unlink(request->getConfigedPath().c_str());
	request->setStateCode(204);
	headers.push_back(getServerHeader(request));
	headers.push_back(getDateHeader(request));
	headers.push_back(getContentTypeHeader(request));
	headers.push_back(getContentLengthHeader(request));
	headers.push_back(getLastModifiedHeader(request));
	headers.push_back(getConnectionHeader(request));
	for (std::vector<std::string>::iterator it = headers.begin(); it != headers.end(); it++)
	{
		erase_white_space(*it);
		ret += *it;
	}
	ret += "\r\n";
	ret += request->getBody() + "\r\n";
	return (ret);
}

std::string Server::getServerHeader(ParsedRequest *request)
{
	return ("Server : " + request->getServerName());
}

std::string Server::getDateHeader(ParsedRequest *request)
{
	time_t now = time(NULL);
	std::string ret = (ctime(&now));
	// todo make form like Wed, 02 Jun 2021 11:24:33 GMT
	return ("Date : " + ret);
}


std::string Server::getContentTypeHeader(ParsedRequest *request)
{
	// todo load content-type
	return ("Content-type : temp");
}

std::string Server::getContentLengthHeader(ParsedRequest *request)
{
	return ("Content-Length : " + std::to_string(int(request->getBody().length())));
}

std::string Server::getLastModifiedHeader(ParsedRequest *request)
{
	struct stat st;

	stat(request->getConfigedPath().c_str(), &st);
//	todo cutomize to real lastModified
//  todo not expecting time
	std::string ret(ctime(&st.st_mtime));
	return ("Last-Modified : " + ret);
}

std::string Server::getConnectionHeader(ParsedRequest *request)
{
	if (request->getStateCode() / 100 == 2)
		return ("Connection : keep-alive");
	else
		return ("Connection : close");
}


std::string Server::getStateText(int state)
{
	return (_status[state]);
}

std::string Server::erase_white_space(std::string &s)
{
	if (s.find_last_of('\n') == s.length() - 1)
		s.resize(s.length() - 1);
	if (s.find_last_of('\r') == s.length() - 1)
		s.resize(s.length() - 1);
	return (s);
}
