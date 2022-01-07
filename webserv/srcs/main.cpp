#include <webserv.hpp>
#include "ServerManager.hpp"

int main(int argc, char *argv[])
{
	ServerManager manager;

	try {
		manager.config(argc, argv);
		manager.run();
	}
	catch (std::exception &e) {
		ft::Log(Error, e.what());
	}
	manager.close();

	return (0);
}
