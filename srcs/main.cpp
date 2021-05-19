#include <webserv.hpp>

#include "ServerManager.hpp"

int main()
{
	ServerManager manager;

	try
	{
		manager.config("sample.conf");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
