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

/* network C */
# include <sys/socket.h>
# include <netinet/in.h>

/* type C */
# include <sys/types.h>
# include <stddef.h>

/* libft */
namespace ft {
	bool		isspace(char c);
	int			atoi(char *str);
	void		*memset(void *src, int val, size_t size);
	void		fd_zero(struct fd_set *fds);
	void		fd_set(int fd, struct fd_set *fds);
	bool		fd_isset(int fd, struct fd_set *fds);
}

#endif
