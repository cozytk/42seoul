#include <sys/types.h>
#include <sys/socket.h>

int main()
{
	sockaddr_in address;
	int socket_fd;

	/* init */
	memset(&server_addr, 0, sizeof(sockaddr_in));
	/*					IPv4	TCP				*/
	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(8080);
}
