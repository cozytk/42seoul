#include <iostream>
#include <string>
#include <array>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

static std::array<std::string, 7> methods = {
        "PUT",
	"GET",
	"HEAD",
	"POST",
	"OPTIONS",
	"TRACE",
   "DELETE"
};

std::string createStartLine(std::string method, std::string path) {
	std::string	start;

	start = method + " " + path + " HTTP/1.1\r\n";
	return start;
}

std::string createHeader(std::string port) {
	std::string	start;

	start = "Host: localhost:" + port + "\r\n"
"User-Agent: eval_test\r\n"
"Accept: text/html\r\n"
"Date: 2021\r\n"
"Accept-Language: en-US,en;q=0.9\r\n";
	return start;
}

std::string createRequest(std::string method, char **argv) {
	std::string request;
	std::string port = argv[1];
	std::string path = argv[2];

	request = createStartLine(method, path) + createHeader(port);
	if (method == "POST" || method == "PUT")
	{
		request += "Content-Type: text/html\r\n"
		"Content-Length: 5\r\n\r\n12345";
	}
	request += "\r\n";
	return request;
}

void		readResponse(int socket) {
	char response[10000];
	int reade_size = 0;

	reade_size = read(socket, response, 10000);
	response[reade_size] = '\0';
	std::cout << "✅ " << response << std::endl;
}

void		runTest(int socket, char **argv) {
	std::string request;
	for (size_t i = 0; i < methods.size(); i++)
	{
		std::cout << " ****************" << i << std::endl;
		request = createRequest(methods[i], argv);
		std::cout << "❓ " << request << std::endl;
		write(socket, request.c_str(), request.length());
		request = "";
		sleep(1);
		readResponse(socket);
	}
}

int	main(int argc, char **argv) {

	int reade_size = 0;
	int socket;
	sockaddr_in server_addr;

	socket = ::socket(PF_INET, SOCK_STREAM, 0);

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(8082);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	connect(socket, (sockaddr *)&server_addr, sizeof(server_addr));
	runTest(socket, argv);
	::close(socket);
}

// # Header

// * Accept-Charsets
// * Accept-Language
// * Allow
// * Authorization
// * Content-Language
// * Content-Length
// * Content-Location
// * Content-Type
// * Date
// * Host
// * Last-Modified
// * Location
// * Referer
// * Retry-After
// * Server
// * Transfer-Encoding
// * User-Agent
// * WWW-Authenticate
