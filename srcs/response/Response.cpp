#include "../../incs/Response.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

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


std::map<int, std::string> Response::_status = make_status();

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

std::map<std::string, std::string> Response::_mime_types = makeMimeType();

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

Response::Response()
{}

Response::Response(ParsedRequest *request, Server *server)
: _request(request), _server(server)
{

}

/* ************************************************************************** */
/* ------------------------------- DESTRUCTOR ------------------------------- */
/* ************************************************************************** */

Response::~Response()
{
}

/* ************************************************************************** */
/* -------------------------------- OVERLOAD -------------------------------- */
/* ************************************************************************** */

Response& Response::operator=(const Response& obj)
{
	if (this == &obj)
		return (*this);
	return (*this);
}

/* ************************************************************************** */
/* --------------------------------- GETTER --------------------------------- */
/* ************************************************************************** */

std::string	Response::getResponseBody() {
	return (this->_response_body);
}

std::string Response::getServerHeader(ParsedRequest *request)
{
	return ("Server: " + request->getServerName());
}

std::string Response::getDateHeader(ParsedRequest *request)
{
	time_t now = time(NULL);
	char buf[1024];
	struct tm *local_tm;

	local_tm = localtime(&now);
	strftime(buf, sizeof(buf), "%a, %d %b %Y %X GMT", local_tm);
	std::string ret(buf);
	return ("Date: " + ret);
}

std::string Response::getContentTypeHeader(ParsedRequest *request)
{
	std::string path = request->getConfigedPath();
	std::string mime_type = _mime_types[path.substr(path.rfind('.') + 1)];

	if (mime_type.empty())
		mime_type = "application/octet-stream";
	return ("Content-type: " + mime_type);
}

std::string Response::getContentLengthHeader(ParsedRequest *request)
{
	return ("Content-Length: " + ft::to_string(int(getResponseBody().length())));
}

std::string Response::getLastModifiedHeader(ParsedRequest *request)
{
	struct stat st;
	char buf[1024];
	struct tm *local_tm;

	ft::memset(&st, 0, sizeof(struct stat));
	stat(request->getConfigedPath().c_str(), &st);
	local_tm = localtime(&st.st_mtime);
	strftime(buf, sizeof(buf), "%a, %d %b %Y %X GMT", local_tm);
	std::string ret(buf);
	return ("Last-Modified: " + ret);
}

std::string Response::getConnectionHeader(ParsedRequest *request)
{
	if (request->getStateCode() / 100 == 2)
		return ("Connection: keep-alive");
	else
		return ("Connection: close");
}

std::string Response::getDefaultErrorPage(ParsedRequest* request)
{
	return ("<html><body><h1>" + ft::to_string(request->getStateCode()) + " " + _status[request->getStateCode()] + "</h1></body></html>");
}

std::string Response::getState(ParsedRequest* request)
{
	return ("HTTP/1.1 " + ft::to_string(request->getStateCode()) + " " + request->getStateText() + "\r\n");
}

std::string Response::getResponse(AutoIndex &autoindex, CGI &cgi)
{
	std::string response;
	std::string path = _request->getConfigedPath();
    std::string extension = path.substr(path.rfind('.') + 1);

    /*
     * todo: update condition
     */
	if (extension == "bla" || extension == "bad_extension") {
		cgi.execute(_request);
		_response_body = runCGI(_request, cgi.getBuffer());
		response = response200(_request);
	}
	else if (_request->getStateCode() / 100 != 2){
		if ( _request->getHeaders()["Type"] == "PUT" && !_request->getHeaders()["Path"].compare(0, 9, "/put_test"))
            response = runPut(_request);
        else if (_request->getHeaders()["Type"] == "POST" && _request->getHeaders()["Path"] == "/post_body")
            response = runPost(_request);
		else
			response = response400(_request);
	}
	else if (_request->getAutoIndex()) {
		_response_body = autoindex.make();
		response = response200(_request);
	}
    else if (_request->getHeaders()["Type"] == "POST") {
        response = runPost(_request);
    }
	else if (_request->getHeaders()["Type"] == "GET") {
		response = runGet(_request);
	}
	else if (_request->getHeaders()["Type"] == "DELETE") {
		response = runDelete(_request);
	}
	else if (_request->getHeaders()["Type"] == "PUT") {
		response = runPut(_request);
	}
	else {
		_request->setStateCode(400);
		response = response400(_request);
	}
	return (response);
}

/* ************************************************************************** */
/* --------------------------------- SETTER --------------------------------- */
/* ************************************************************************** */

/* ************************************************************************** */
/* ------------------------------- EXCEPTION -------------------------------- */
/* ************************************************************************** */

/* ************************************************************************** */
/* ---------------------------- MEMBER FUNCTION ----------------------------- */
/* ************************************************************************** */

std::string	Response::runPut(ParsedRequest *request) {
	ParsedRequest	*req = this->_request;
	FILE	*file = fopen(req->getConfigedPath().c_str(), "w");

	if (file != NULL)
	{
		fputs(request->getBody().c_str(), file);
//		std::cout << "♻️ put file update" << std::endl;
	}
	else
	{
		fputs(request->getBody().c_str(), file);
//		std::cout << "🔆 put file created" << std::endl;
	}
	if (_request->getStateCode() == 404)
	{
		request->setStateCode(201);
		request->setStateText("Created");
	}
	else
		request->setStateCode(200);
	// todo response200 return
	return response200(request);
}

std::string Response::runGet(ParsedRequest *request)
{
	setResponseBody(request);
	request->setStateCode(200);
    request->setStateText("OK");
	return (response200(request));
}

std::string Response::runPost(ParsedRequest *request)
{
	if (request->getBody().length() == 0)
		return (runGet(request));
	else if (request->getBody().length() > request->getMaxBody())
    {
	    request->setStateCode(413);
	    request->setStateText("Payload Too Large");
        return (response400(request));
    }
	_response_body = request->getBody();
	request->setStateCode(200);
    request->setStateText("OK");
	return (response200(request));
}

std::string Response::runDelete(ParsedRequest *request)
{
	unlink(request->getConfigedPath().c_str());
	return (getDateHeader(request) + "\r\n\r\n<html><body>File deleted.</body></html>\r\n");
}

void		Response::setResponseHeadear(std::vector<std::string> &headers, ParsedRequest *request)
{
	headers.push_back(getServerHeader(request));
	headers.push_back(getDateHeader(request));
	headers.push_back(getContentTypeHeader(request));
	headers.push_back(getContentLengthHeader(request));
	headers.push_back(getConnectionHeader(request));
}

void		Response::setResponseBody(ParsedRequest *request)
{
	/*
	 * Use cstdio instead of fstream -> fstream is slower than cstdio.
	 * todo (bonus) char to wchar for unicord
	 */
	FILE *file;
	char *buf;
	long max_body = request->getMaxBody();

	if (request->getStateCode() / 100 == 2)
		file = fopen(request->getConfigedPath().c_str(), "r");
	else if (!(file = fopen(request->getErrorPage()[ft::to_string(request->getStateCode())].c_str(), "r")))
	{
		this->_response_body = getDefaultErrorPage(request);
		return ;
	}
	if (max_body >= 0)
	{
		buf = new char[max_body + 1]();
		fread(buf, 1, max_body, file);
		buf[max_body] = '\0';
	}
	else
	{
		fseek(file, 0, SEEK_END);
		max_body = ftell(file);
		rewind(file);
		buf = new char[max_body + 1]();
		fread(buf, 1, max_body, file);
		buf[max_body] = '\0';
	}
	this->_response_body = buf;
	delete buf;
	buf = 0;
	fclose(file);
	return ;
}

std::string Response::response200(ParsedRequest *request)
{
	std::vector<std::string> headers;
	std::string ret;
	headers.push_back(getState(request));
	headers.push_back(getServerHeader(request));
	headers.push_back(getDateHeader(request));
	headers.push_back(getContentTypeHeader(request));
	headers.push_back(getContentLengthHeader(request));
	headers.push_back(getConnectionHeader(request));
	headers.push_back(getLastModifiedHeader(request));
	for (std::vector<std::string>::iterator it = headers.begin(); it != headers.end(); it++)
	{
		erase_white_space(*it);
		ret += *it + "\r\n";
	}
	ret += "\r\n";
	ret += this->getResponseBody();
	return (ret);
}

std::string Response::response400(ParsedRequest *request)
{
	std::vector<std::string> headers;
	std::string ret;

	headers.push_back(getState(request));
	headers.push_back(getServerHeader(request));
	headers.push_back(getDateHeader(request));
	headers.push_back(getContentTypeHeader(request));
	headers.push_back(getContentLengthHeader(request));
	headers.push_back(getConnectionHeader(request));
	setResponseBody(request);
	for (std::vector<std::string>::iterator it = headers.begin(); it != headers.end(); it++)
	{
		erase_white_space(*it);
		ret += *it + "\r\n";
	}
	ret += "\r\n";
	ret += this->getResponseBody();
	return (ret);
}

std::string Response::runCGI(ParsedRequest *request, std::string &cgi_body)
{
	/*
	 * todo passing cgi info to request Class
	 */
//	std::cout << "CGI_BODY_SIZE IS " << cgi_body.size() << std::endl;
//	std::string response_body = cgi_body.substr(cgi_body.find(':') + 2);
	std::string response_body = cgi_body.substr(cgi_body.find("\r\n\r\n") + 4);
//	std::cout << "RESPONSE_BODY_SIZE IS " << response_body.size() << std::endl;
//	std::cout << "------------cgi start-------------\n";
//	std::cout << cgi_body;
//	std::cout << "------------cgi end-------------\n";
//	std::cout << "In CGI, std::string body\n" << body.substr(0, body.find("\r\n\r\n")) << "------------------------\n";
//	std::cout << body.substr(body.find("\r\n\r\n") + 4).length() << std::endl;
//	return (body.substr(body.find("\r\n\r\n") + 4));
//	return ("Status: " + ft::to_string(request->getStateCode()) + "\r\n" + "Content-type: text/html\r\nContent-length:" + ft::to_string(response_body.length()) +"\r\n\r\n" + response_body);
	request->setStateCode(200);
	request->setStateText("OK");
	return (response_body);
}

std::string Response::erase_white_space(std::string &s)
{
	if (s.find_last_of('\n') == s.length() - 1)
		s.resize(s.length() - 1);
	if (s.find_last_of('\r') == s.length() - 1)
		s.resize(s.length() - 1);
	return (s);
}
