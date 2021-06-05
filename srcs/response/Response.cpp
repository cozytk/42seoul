#include "../../incs/Response.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

Response::Response() {}
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

/* ************************************************************************** */
/* --------------------------------- SETTER --------------------------------- */
/* ************************************************************************** */

/* ************************************************************************** */
/* ------------------------------- EXCEPTION -------------------------------- */
/* ************************************************************************** */

/* ************************************************************************** */
/* ---------------------------- MEMBER FUNCTION ----------------------------- */
/* ************************************************************************** */

std::string	Response::runPut(ParsedRequest *request, int state) {
	ParsedRequest	*req = this->_request;
	FILE	*file = fopen(req->getConfigedPath().c_str(), "w");

	if (file != NULL)
	{
		fputs(request->getBody().c_str(), file);
		std::cout << "♻️ put file update" << std::endl;
	}
	else
	{
		fputs(request->getBody().c_str(), file);
		std::cout << "🔆 put file created" << std::endl;
	}
	if (state == 404)
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
	return (response200(request));
}

std::string Response::runPost(ParsedRequest *request)
{
	if (request->getBody().length() == 0)
		return (runGet(request));
	request->setStateCode(400);
	return (response400(request));
}

std::string Response::runDelete(ParsedRequest *request)
{
	unlink(request->getConfigedPath().c_str());
	return (getDateHeader(request) + "\r\n\r\n<html><body>File deleted.</body></html>\r\n");
}

void		Response::setResponseHeadear(ParsedRequest *request)
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

	headers.push_back(getServerHeader(request));
	headers.push_back(getDateHeader(request));
	headers.push_back(getContentTypeHeader(request));
	headers.push_back(getContentLengthHeader(request));
	headers.push_back(getConnectionHeader(request));
	setCommonHeadear(request);
	headers.push_back(getLastModifiedHeader(request));
	for (std::vector<std::string>::iterator it = headers.begin(); it != headers.end(); it++)
	{
		erase_white_space(*it);
		ret += *it + "\r\n";
	}
	ret += "\r\n";
	ret += this->getResponseBody(request);
	return (ret);
}

std::string Response::response400(ParsedRequest *request)
{
	std::vector<std::string> headers;
	std::string ret;

	headers.push_back(getServerHeader(request));
	headers.push_back(getDateHeader(request));
	headers.push_back(getContentTypeHeader(request));
	headers.push_back(getContentLengthHeader(request));
	headers.push_back(getConnectionHeader(request));
	setResponseBody(request);
	setCommonHeadear(request);
	for (std::vector<std::string>::iterator it = headers.begin(); it != headers.end(); it++)
	{
		erase_white_space(*it);
		ret += *it + "\r\n";
	}
	ret += "\r\n";
	ret += this->getResponseBody(request);
	return (ret);
}

std::string Response::responseCGI(ParsedRequest *request, const std::string & body)
{
	return ("Status: " + ft::to_string(request->getStateCode()) + "\r\n" + "Content-type: text/html\r\n" + body + "\r\n");
}

std::string Response::erase_white_space(std::string &s)
{
	if (s.find_last_of('\n') == s.length() - 1)
		s.resize(s.length() - 1);
	if (s.find_last_of('\r') == s.length() - 1)
		s.resize(s.length() - 1);
	return (s);
}
