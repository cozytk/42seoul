#include <arpa/inet.h>
#include <webserv.hpp>

void ft::Log(LogLevel lv, std::string const &log) {
	time_t rawtime;
	tm *timeinfo;
	char buffer[24];
	std::string color = "";

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 40, "%F %T", timeinfo);
	switch (static_cast<int>(lv)) {
	case Warning:
		color = YELLOW; break;
	case Error:
		color = RED;
	}
	std::cout << color << '[' << buffer << "] " << log << RESET << std::endl;
}

std::string	ft::base64::encode(std::string const &str) {
	std::string buffer = "";
	int tmp;
	int arr;
	int count;

	count = 0;
	while (count < (str.length() + 2) / 3) {
		arr = 0;
		for (int i = 0; i < 3; i++) {
			tmp = static_cast<int>(str[count * 3 + i]);
			arr |= (tmp << (2 - i) * 8);
		}
		for (int i = 0; i < 4; i++) {
			if (count == (str.length() + 2) / 3 - 1 && i >= 1 && count * 3 + i - 1 >= str.length())
				buffer += '=';
			else
				buffer += ft::base64::alphabet[(arr >> (3 - i) * 6) & 0b00111111];
		}
		count++;
	}
	return (buffer);
}

std::string	ft::base64::decode(std::string const &str) {
	std::string buffer = "";
	int arr;
	int tmp;
	int count;

	count = 0;
	while (count < str.length() / 4) {
		arr = 0;
		for (int i = 0; i < 4; i++) {
			tmp = static_cast<int>(ft::base64::alphabet.find(str[count * 4 + i]));
			if (tmp != -1)
				arr |= (tmp << (3 - i) * 6);
		}
		for (int i = 0; i < 3; i++)
			if (!(count == str.length() / 4 - 1 && str[count * 4 + i + 1] == '='))
				buffer += static_cast<char>(arr >> (2 - i) * 8);
		count++;
	}
	return (buffer);
}

bool		ft::isspace(char c) {
	if (c == 0x20 || (0x09 <= c && c <= 0x0d))
		return (true);
	return (false);
}

int			ft::atoi(char *str) {
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

int			ft::htod(char *str) {
	const char	*alphabet = "0123456789abcdef";
	int			ret;
	int			minus;

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
	while (ft::index(*str, alphabet) != -1)
	{
		ret *= 16;
		ret += ft::index(*str, alphabet);
		str++;
	}
	return (minus * ret);
}

int			ft::index(char c, const char *arr) {
	int i = 0;

	while (arr[i]) {
		if (arr[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

std::string	ft::to_string(int n)
{
	std::string ret = "";
	int number = n;

	if (n == 0)
		return (std::string("0"));
	if (n < 0)
		number *= -1;
	while (number) {
		ret += static_cast<char>(number % 10 + '0');
		number /= 10;
	}
	if (n < 0)
		ret += '-';
	return (std::string(ret.rbegin(), ret.rend()));
}

void	ft::trim_space(std::string &str) {
	while (9 <= str[0] && str[0] <= 13)
		str.erase(str.begin());
}

void	ft::trim_chunked(std::string &str) {
	std::string ret = "";
	int cursor;
	int chunked_length;
	std::string chunked_buffer;
	std::string chunked_length_buffer;

	ret.reserve(str.length());
	ret += str.substr(0, str.find("\r\n\r\n") + 4);
	cursor = ret.length();

	while (42) {
		chunked_length_buffer = str.substr(cursor, str.find("\r\n", cursor) - cursor);
		chunked_length = ft::htod(const_cast<char *>(chunked_length_buffer.c_str()));
		if (chunked_length == 0)
			break ;
		cursor += chunked_length_buffer.length() + 2;
		chunked_buffer = str.substr(cursor, chunked_length);
		cursor += chunked_buffer.length() + 2;
		ret += chunked_buffer;
	}
	str = ret;
}

int		ft::getLength(std::string const &buffer) {
	int header_eof;
	std::string header;
	std::string length;

	length = "";
	header_eof = buffer.find("\r\n\r\n");
	header = std::string(buffer, 0, header_eof);
	if (header.find("Content-Length: ") != std::string::npos)
		length = std::string(header, header.find("Content-Length: ") + 16);
	if (header.find("content-length: ") != std::string::npos)
		length = std::string(header, header.find("content-length: ") + 16);
	if (length == "")
		return (-1);
	return (atoi(const_cast<char *>(length.c_str())));
}

bool	ft::getChunked(std::string const &buffer) {
	int header_eof;
	std::string header;

	header_eof = buffer.find("\r\n\r\n");
	header = std::string(buffer, 0, header_eof);
	if (header.find("Transfer-Encoding: chunked") != std::string::npos)
		return (true);
	return (false);
}

void	*ft::memset(void *_src, int val, size_t size) {
	unsigned char *src;
	unsigned char *ptr;

	src = reinterpret_cast<unsigned char *>(_src);
	ptr = src;
	while (size-- > 0)
		*(src++) = val;
	return (ptr);
}

size_t	ft::strlcpy(char *dst, char *src, size_t size)
{
	unsigned long	count;
	unsigned long	ret;

	count = 0;
	ret = 0;
	if (!dst || !src)
		return (0);
	while (*(src + ret))
		ret++;
	if (size > 0)
	{
		while (count < size - 1 && *src)
		{
			*(dst++) = *(src++);
			count++;
		}
		*dst = '\0';
	}
	return (ret);
}

int		ft::tolower(int c) {
	if ('A' <= c && c <= 'Z')
		c += 32;
	return (c);
}

void	ft::fd_zero(::fd_set *fds) {
	ft::memset(fds, 0, sizeof(*fds));
}

void	ft::fd_set(int fd, ::fd_set *fds) {
	fds->fds_bits[fd / 32] |= (1 << (fd % 32));
}

void	ft::fd_sets(int fd, struct fds *fds) {
	fd_set(fd, &fds->read);
	fd_set(fd, &fds->write);
	fd_set(fd, &fds->except);
}

void	ft::fd_clr(int fd, ::fd_set *fds) {
	fds->fds_bits[fd / 32] &= (~(1 << (fd % 32)));
}

void	ft::fd_clrs(int fd, struct fds *fds) {
	fd_clr(fd, &fds->read);
	fd_clr(fd, &fds->write);
	fd_clr(fd, &fds->except);
}

bool	ft::fd_isset(int fd, ::fd_set *fds) {
	if ((fds->fds_bits[fd / 32] & (1 << (fd % 32))) != 0)
		return (true);
	return (false);
}

std::pair<std::string, std::string> ft::headerPair(std::string str) {
	int pos = str.find(": ");
	std::string header = std::string(str, 0, pos);
	ft::transform(header.begin(), header.end(), ft::tolower);
	//return (std::make_pair<std::string, std::string>(header, std::string(str, pos + 2)));
	return (std::make_pair(header, std::string(str, pos + 2)));
}
