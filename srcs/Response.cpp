#include "Response.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

std::map<int, std::string> make_status ()
{
	std::map<int, std::string> status_map;

	status_map[100] = "Continue";
	status_map[200] = "OK";
	status_map[201] = "Created";
	status_map[202] = "Accepted";
	status_map[204] = "No Content";
	status_map[205] = "Reset Content";
	status_map[206] = "Partial Content";
	status_map[299] = "CGI OK";
	status_map[300] = "Multiple Choice";
	status_map[301] = "Moved Permanently";
	status_map[303] = "See Other";
	status_map[305] = "Use Proxy";
	status_map[307] = "Temporary Redirect";
	status_map[400] = "Bad Request";
	status_map[401] = "Unauthorized";
	status_map[403] = "Forbidden";
	status_map[404] = "Not Found";
	status_map[405] = "Method Not Allowed";
	status_map[406] = "Not Acceptable";
	status_map[407] = "Proxy Authentication Required";
	status_map[408] = "Request Timeout";
	status_map[409] = "Conflict";
	status_map[410] = "Gone";
	status_map[411] = "Length Required";
	status_map[412] = "Precondition Failed";
	status_map[413] = "Payload Too Large";
	status_map[414] = "URI Too Long";
	status_map[415] = "Unsupported Media Type";
	status_map[416] = "Requested Range Not Satisfiable";
	status_map[417] = "Expectation Failed";
	status_map[500] = "Internal Server Error";
	status_map[501] = "Not Implemented";
	status_map[503] = "Service Unavailable";
	status_map[504] = "Gateway Timeout";
	status_map[505] = "HTTP Version Not Supported";

	return (status_map);
}

std::map<int, std::string> Response::status = make_status();

/* static variable code */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

Response::Response() {}
Response::Response(/* constructor parameter */)
: /* constructor initialize list */ {
	/* constructor code */
}

Response::Response(const Response& copy)
: /* copy-constructor initialize list */
{
	/* copy-constructor code */
}

/* ************************************************************************** */
/* ------------------------------- DESTRUCTOR ------------------------------- */
/* ************************************************************************** */

Response::~Response()
{
	/* destructor code */
}

/* ************************************************************************** */
/* -------------------------------- OVERLOAD -------------------------------- */
/* ************************************************************************** */

Response& Response::operator=(const Response& obj)
{
	if (this == &obj)
		return (*this);
	/* overload= code */
	return (*this);
}

std::ostream&
operator<<(std::ostream& out, const Response& response)
{
	/* ostream output overload code */
	return (out);
}

/* ************************************************************************** */
/* --------------------------------- GETTER --------------------------------- */
/* ************************************************************************** */

/* getter code */

/* ************************************************************************** */
/* --------------------------------- SETTER --------------------------------- */
/* ************************************************************************** */

/* setter code */

/* ************************************************************************** */
/* ------------------------------- EXCEPTION -------------------------------- */
/* ************************************************************************** */

/* exception code */

/* ************************************************************************** */
/* ---------------------------- MEMBER FUNCTION ----------------------------- */
/* ************************************************************************** */

void Response::sortMethod(Connection& connection, const Request& request)
{
	std::string method = request.getHeaders()["Type"];

	/*
	 * need to 405(01), 401, 400(22), 403(01) response
	 */

	if (method == "TRACE")
		runTrace(connection, request);
	else if (request.getUriType() == "DIRECTORY")
		return (runAutoindex(connection, request));
	else if (request.getUriType() == "CGI_PROGRAM")
		return (runCGI(connection, request));
	else if (method == "GET")
		runGetHead(connection, request, GET);
	else if (method == "HEAD")
		runGetHead(connection, request, HEAD);
	else if (method == "POST")
		runPost(connection, request);
	else if (method == "PUT")
		runPut(connection, request);
	else if (method == "DELETE")
		runDelete(connection, request);
	else if (method == "OPTIONS")
		runOptions(connection, request);
	else
		throw (400);
}

/*
 * autoindex
 */

time_t Response::getLastModifiedHeader(const std::string& path)
{
	struct stat buf;
	__darwin_time_t ret;

	ft::memset(&buf, 0, sizeof(struct stat));
	stat(path.c_str(), &buf);
	ret = buf.st_mtimespec.tv_sec;
	return (ret);
}

void Response::runGetHead(Connection& connection, const Request& request, bool method)
{
	std::string path = request.getPathTranslated();
	std::string body;

	try {
		body = fileToString(path, _limitClientBodySize);
	} catch (std::overflow_error& e) {
		return (response400(connection, 413));
	}
	headers_t headers(1, getMimeTypeHeader(path));
	if (headers[0].empty())
		return (response400(connection, 415));
	headers.push_back(reinterpret_cast<const char *>(getLastModifiedHeader(path)));
	if (method == HEAD)
		headers.push_back("content-length:" + ft::to_string(int(body.size())));
	return (response200(connection, 200, headers, body));
}

std::string Request::getMimeTypeHeader() const
{
	return (_mimeTypeHeader);
}



/*
void
Server::executeTrace(Connection& connection, const Request& request)
{
	createResponse(connection, 200, headers_t(1, "Content-Type:text/plain"), request.get_m_origin());
}

void
Server::executePost(Connection& connection, const Request& request)
{
	if (request.get_m_headers().find("Content-Length")->second == "0")
		return (executeGet(connection, request));
	else
		return (createResponse(connection, 40023));
}

void
Server::executeOptions(Connection& connection, const Request& request) {
	if (request.get_m_uri() == "*")
		return (createResponse(connection, 200, headers_t(1, std::string("Allow:") + SERVER_ALLOW_METHODS)));
	headers_t headers(1, "Allow:" + ft::containerToString(request.get_m_location()->get_m_allow_method(), ", "));
	return (createResponse(connection, 200, headers));
}

void
Server::executePut(Connection& connection, const Request& request)
{
	int fd;
	struct stat buf;
	int count;

	stat(request.get_m_script_translated().c_str(), &buf);
	headers_t headers(1, getMimeTypeHeader(request.get_m_path_translated()));
	// if (headers[0].empty())
	// 	return (createResponse(request.get_m_connection(), 41503));
	if ((fd = open(request.get_m_script_translated().c_str(), O_RDWR | O_CREAT | O_TRUNC, 0777)) == -1)
		return (createResponse(connection, 50003));
	if (!request.get_m_content().empty() && (count = write(fd, request.get_m_content().c_str(), request.get_m_content().size()) <= 0))
	{
		close(fd);
		if (count == 0 || count == -1)
			throw (Server::IOError((("IO error detected to write body in executePut") + ft::to_string(fd)).c_str()));
		return (createResponse(connection, 50004));
	}
	close(fd);
	if (S_ISREG(buf.st_mode))
		return (createResponse(connection, 204));
	headers.push_back("Location:" + m_host + "/" + request.get_m_uri());
	return (createResponse(connection, 201, headers, request.get_m_content()));
}

void
Server::executeDelete(Connection& connection, const Request& request) {
	if (unlink(request.get_m_path_translated().c_str()) == -1)
		createResponse(connection, 204);
	else
		return (createResponse(connection, 204));
}

 */


void Response::response100(Connection& connection, int status, headers_t headers, std::string body)
{
}

void Response::response200(Connection& connection, int status, headers_t headers, std::string body)
{
	headers.push_back(setLastModified());
	headers.push_back(setServerName());
	/* todo cgi response
	if (status == CGI_SUCCESS_CODE)
		createCGIResponse(status, headers, body);
	*/

	/*
	 * todo when Trasfer-Encoding, skip
	 */
	headers.push_back(setContentLength(body));
	if (!body.empty())
		headers.push_back(setContentLanguage());
	if (connection.getMethod() == "HEAD")
		body = "";
	/*
	 * todo response generate, header factoring
	 */
}

void Response::response300(Connection& connection, int status, headers_t headers, std::string body)
{

}

void Response::response400(Connection& connection, int status)
{
	headers_t headers = headers_t();
	std::string body;

	body = "";
	headers.push_back(setLastModified());
	headers.push_back(setServerName());
	/* todo cgi response */
	body = _errorPage;
	body.replace(body.find("#ERROR_CODE"), 11, ft::to_string(status));
	body.replace(body.find("#ERROR_CODE"), 11, ft::to_string(status));
	body.replace(body.find("#ERROR_DESCRIPTION"), 18, Response::status[status]);
	body.replace(body.find("#ERROR_DESCRIPTION"), 18, Response::status[status]);
	body.replace(body.find("#PORT"), 5, ft::to_string(_port));
	/*
	 * todo Transfer-Encoding
	 */
	headers.push_back(setContentLanguage());
	headers.push_back("Connection:close");
	/*
    * todo response generate, header factoring
	 */

}
void Response::response500(Connection& connection, int status, headers_t headers, std::string body)
{

}
std::string Response::fileToString(std::string path, int limit)
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

std::string Response::getServerName() const
{

}


std::string Response::writeResponseMsg() const
{
	std::string msg;
	std::map<std::string, std::string>::const_iterator it = this->_headers.begin();
}

std::string Response::setLastModified()
{
	char buff[1024];
	struct tm *t;
	time_t now = time(NULL);

	t = localtime(&now);
	strftime(buff, 1024, "%a, %d %b %Y %X GMT", t);
	return ("Last-Modified:" + std::string(buff));
}

std::string Response::setServerName()
{
	return ("Server: " + getServerName());
}

std::string Response::setContentLength(const std::string& body)
{
	return ("Content-Length:" + ft::to_string(body.size()));
}

std::string Response::setContentLanguage()
{
	return ("Content-Language:ko-KR");
}
