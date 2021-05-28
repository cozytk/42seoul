#include <webserv.hpp>

#include "ServerManager.hpp"
#include "CGI.hpp"

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
	CGI cgi;

	cgi.execute();
	std::cout << cgi.getBuffer() << std::endl;
}
