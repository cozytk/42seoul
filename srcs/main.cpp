#include <webserv.hpp>

#include "server/ServerManager.hpp"
#include "config/Config.hpp"

int main()
{
	ServerManager manager;

	try
	{
		manager.config("sample.conf");
		manager.run();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
