#include <webserv.hpp>

bool		ft::isspace(char c)
{
	if (c == 0x20 || (0x09 <= c && c <= 0x0d))
		return (true);
	return (false);
}

int			ft::atoi(char *str)
{
	int		ret;
	int		minus;

	ret = 0;
	minus = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		minus = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	return (minus * ret);
}

void	*ft::memset(void *_src, int val, size_t size)
{
	unsigned char *src;
	unsigned char *ptr;

	src = reinterpret_cast<unsigned char *>(_src);
	ptr = src;
	while (size-- > 0)
		*(src++) = val;
	return (ptr);
}

void	ft::fd_zero(struct fd_set *fds)
{
	ft::memset(fds, 0, sizeof(*fds));
}

void	ft::fd_set(int fd, struct fd_set *fds)
{
	fds->fds_bits[fd / 32] |= (1 << (fd % 32));
}

bool	ft::fd_isset(int fd, struct fd_set *fds)
{
	if ((fds->fds_bits[fd / 32] & (1 << (fd % 32))) != 0)
		return (true);
	return (false);
}
