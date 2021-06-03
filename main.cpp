#include <iostream>
#include <cstdio>

#define BUFFER_SIZE 1024

int main(int ac, char **av)
{
	FILE *file;

	std::string ret;
	char *buf;
	long max_body;

	if (ac != 2)
	{
		std::cout << "Argument plz\n";
		return (1);
	}
	max_body = std::atoi(av[1]);
	if (!(file = fopen("file_should_exist_after", "r")))
	{
		std::cout << "open failed\n";
		return (1);
	}
	if (max_body >= 0)
	{
		buf = new char[max_body]();
		fread(buf, 1, max_body, file);
	} else
	{
		fseek(file, 0, SEEK_END);
		max_body = ftell(file);
		rewind(file);
		buf = new char[max_body]();
		fread(buf, 1, max_body, file);
	}
	ret = buf;
	delete buf;
	fclose(file);
	std::cout << ret;
	return (0);
}

//
// Created by Taekyun Kim on 6/3/21.
//

