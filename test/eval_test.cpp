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

static std::array<std::string, 8> methods = {
	"GET",
	"HEAD",
	"POST",
	"PUT",
	"DELETE",
	"TRACE"
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

int	main(int argc, char **argv) {
	std::string port = argv[1];
	std::string path = argv[2];
	std::string request = "curl localhost:8082/index.html";
	std::string command = "curl ";
	char response[10000];
	int reade_size = 0;
	int socket;
	sockaddr_in server_addr;

	socket = ::socket(PF_INET, SOCK_STREAM, 0);

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(8082);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(socket, (sockaddr *)&server_addr, sizeof(server_addr));

	for (size_t i = 0; i < methods.size(); i++)
	{
		request = createStartLine(methods[i], path) + createHeader(port);
		std::cout << "🦊 " << request << std::endl;
		if (methods[i] == "POST" || methods[i] == "PUT")
		{
			request += "Content-Type: text/html\r\n"
			"Content-Length: 5\r\n\r\n12345";
		}
		request += "\r\n";
		write(socket, request.c_str(), request.length());
		sleep(1);
		reade_size = read(socket, response, 10000);
		response[reade_size] = '\0';
		std::cout << "✅ " << response << std::endl;
	}
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
