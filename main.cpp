#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sys/stat.h>

int main(int ac, char **av)
{
	struct stat sb;
	(void)ac;
	int buf = atoi(av[1]);
	std::ifstream file("Makefile");
	char s[buf];
	stat("Makefile", &sb);

	if (file.is_open())
	{
		std::cout << "opened\n";
		file.read(s, buf);
		std::cout << s << std::endl;
	}
	else
		std::cout << "Not opened\n";

	std::cout << ctime(&sb.st_mtime) << std::endl;
	return (0);
}
