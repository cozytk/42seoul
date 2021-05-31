#include <webserv.hpp>

#include "ServerManager.hpp"

int main()
{
	/*
	ServerManager manager;

	try
	{
		manager.config("sample.conf");
		manager.run();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	manager.serverClose();
	*/
	ft::Log(Log, "test message");
	ft::Log(Warning, "sample.conf is not valid");
	ft::Log(Error, "sample.conf is not found");
}
