#include "utils.hpp"

bool ft::isspace(char c)
{
	if (c == 0x20 || (0x09 <= c && c <= 0x0d))
		return (true);
	return (false);
}
