#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>

std::string header = "HTTP/1.1 200 OK\n"
    "Content-Type: text/html\n\n";

std::string body = "<html>\n"
	"<title>42</title>\n"
	"<body>\n"
	"<div>page 42</div>\n"
	"</body>\n"
	"</html>";

int main()
{
	sockaddr_in address;
	int socket_fd;

	int socket_new;
	int addrlen = sizeof(address);

	char buf[10000];
	int r_bytes = 0;

	/* init */
	memset(&address, 0, sizeof(sockaddr_in));
	/*					IPv4	TCP				*/
	socket_fd = socket(AF_INET, SOCK_STREAM, 0); // fd
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htons(INADDR_ANY);
	address.sin_port = htons(8080);

	bind(socket_fd, (sockaddr *)&address, sizeof(address)); // regist fd to kernel

	listen(socket_fd, 5);

	while (1)
	{
		std::cout << "----------wating--------------------------------" << std::endl;
		socket_new = accept(socket_fd, (sockaddr *)&address, (socklen_t *)&addrlen);
		std::cout << "accept; socket: " << socket_new << std::endl;
		r_bytes = read(socket_new, buf, 10000);
		std::cout << buf << std::endl;
		write(socket_new, (header + body).c_str(), (header + body).length());
		close(socket_new);
	}
	close(socket_fd);
}
