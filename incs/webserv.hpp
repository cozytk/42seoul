#ifndef WEBSERV_HPP
# define WEBSERV_HPP

/* header CPP */
# include <iostream>
# include <vector>
# include <map>
# include <stack>

/* header C */
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>

/* network C */
# include <sys/socket.h>
# include <netinet/in.h>

/* type C */
# include <sys/types.h>
# include <stddef.h>

/* macro */
# define RECV_BUFFER_SIZE 65536
# define WAIT_RECV 0
# define ALL_RECV 1

/* libft */
namespace ft {
	/* class, struct */
	struct fds {
		fd_set read;
		fd_set write;
		fd_set except;
	};

	/* func */
	bool		isspace(char c);
	int			atoi(char *str);
	void		*memset(void *src, int val, size_t size);

	/* fd_set */
	void		fd_zero(struct fd_set *fds);
	void		fd_set(int fd, struct fd_set *fds);
	void		fd_sets(int fd, struct fds *fds);
	void		fd_clr(int fd, struct fd_set *fds);
	void		fd_clrs(int fd, struct fds *fds);
	bool		fd_isset(int fd, struct fd_set *fds);

	/* key, value */
	std::pair<std::string, std::string> headerPair(std::string str);
}

#endif
