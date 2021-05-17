#include <iostream>
#include "config/Config.hpp"
#include "config/ConfigReader.hpp"

void print_all(std::vector<std::string> &v)
{
	for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main()
{
	Config	config;

	try
	{
		config.file("sample.conf");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	print_all(*config["worker_processes"]);
	//std::cout << *config["server"] << std::endl;
//	std::cout << config["server"]["location"].getValue() << std::endl;
}
