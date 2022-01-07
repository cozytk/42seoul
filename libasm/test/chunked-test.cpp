#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>

int main()
{
	std::string header = "POST / HTTP/1.1\r\n"
"Host: 127.0.0.1:8081\r\n"
"User-Agent: Go-http-client/1.1\r\n"
"Transfer-Encoding: chunked\r\n"
"Content-Type: test/file\r\n"
"Accept-Encoding: gzip\r\n\r\n";

	std::string chunked0 = "5\r\nhello\r\n";
	std::string chunked1 = "14\r\nthis is test message\r\n";

	std::string chunked2 = "0\r\n\r\n"; //"1\r\n" //not finish

	int socket;
	sockaddr_in server_addr;

	socket = ::socket(PF_INET, SOCK_STREAM, 0);

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(8080);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(socket, (sockaddr *)&server_addr, sizeof(server_addr));

	write(socket, header.c_str(), header.length());
	sleep(1);
	write(socket, chunked0.c_str(), chunked0.length());
	sleep(1);
	write(socket, chunked1.c_str(), chunked1.length());
	sleep(1);
	write(socket, chunked2.c_str(), chunked2.length());
	sleep(1);

	::close(socket);
}
