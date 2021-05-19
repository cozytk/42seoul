#ifndef SERVER
# define SERVER
# include <vector>
# include "ServerManager.hpp"

//# include "Location.hpp"
class ServerManager;

class Server {
private:
	int						_port;
//	std::vector<Location>	_locations;

public:	
	friend ServerManager;

	Server();
	Server(Server const &other);
	virtual ~Server();
	Server&operator=(Server const &other);

	void run();

};
#endif
