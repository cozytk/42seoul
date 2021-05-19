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

	//std::cout << config["http"][0]["server"].size() << std::endl;
	//print_all(*config["worker_processes"][0]);
	print_all( *config("42", 0)("http", 0)("location", 0)("root", 0) );
	/*
	print_all(*config["http"]["server"]);
	print_all(*config["http"]["server"]["location"]);
	print_all(*config["http"]["server"]["location"]["index"]);
	*/
	//std::cout << *config["server"] << std::endl;
//	std::cout << config["server"]["location"].getValue() << std::endl;
}
