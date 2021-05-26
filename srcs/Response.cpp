#include "connection/Request.hpp"
#include "Response.hpp"

/* ************************************************************************** */
/* ---------------------------- STATIC VARIABLE ----------------------------- */
/* ************************************************************************** */

/* static variable code */

/* ************************************************************************** */
/* ------------------------------ CONSTRUCTOR ------------------------------- */
/* ************************************************************************** */

Response::Response() {}
Response::Response(/* constructor parameter */)
: /* constructor initialize list */
{
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

void
Response::solveRequest(Connection& connection, const Request& request)
{
	Request::Method method = request.getMethod();

	/*
	 * need to 405(01), 401, 400(22), 403(01) response
	 */

	if (method == "TRACE")
		executeTrace(connection, request);
	else if (request.get_uri_type() == "DIRECTORY")
		return (executeAutoindex(connection, request));
	else if (request.get_uri_type() == "CGI_PROGRAM")
		return (executeCGI(connection, request));
	else if (method == "GET")
		executeGet(connection, request);
	else if (method == "HEAD")
		executeHead(connection, request);
	else if (method == "POST")
		executePost(connection, request);
	else if (method == "PUT")
		executePut(connection, request);
	else if (method == "DELETE")
		executeDelete(connection, request);
	else if (method == "OPTIONS")
		executeOptions(connection, request);
	else
		throw (400);
}

/*
 * autoindex
 */

void
Response::executeGet(Connection& connection, const Request& request)
{
	std::string path = request.get_path_translated();
	std::string body;

	try {
		body = ft::getStringFromFile(path, m_limit_client_body_size);
	} catch (std::overflow_error& e) {
		return (createResponse(connection, 41304));
	}
	headers_t headers(1, getMimeTypeHeader(path));
	if (headers[0].empty())
		return (createResponse(connection, 41501));
	headers.push_back(getLastModifiedHeader(path));
	return (createResponse(connection, 200, headers, body));
}

void
Server::executeHead(Connection& connection, const Request& request)
{
	std::string path = request.get_m_path_translated();
	std::string body;

	try {
		body = ft::getStringFromFile(path, m_limit_client_body_size);
	} catch (std::overflow_error& e) {
		return (createResponse(connection, 41305));
	}

	headers_t headers(1, getMimeTypeHeader(path));
	if (headers[0].empty())
		return (createResponse(connection, 41502));
	headers.push_back(getLastModifiedHeader(path));
	headers.push_back("content-length:" + ft::to_string(body.size()));
	return (createResponse(connection, 200, headers));
}

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
