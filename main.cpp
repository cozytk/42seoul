#include <iostream>
#include "config/Conf.hpp"
#include "config/ConfigReader.hpp"

int main()
{
	Conf	config;

	try
	{
		config.file("sample.conf");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

//	std::cout << config["server"].getValue() << std::endl;
//	std::cout << config["server"]["location"].getValue() << std::endl;
}
