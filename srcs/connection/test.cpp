// #include "Request.hpp"
#include <sys/socket.h>
#include <unistd.h>
 #include <sys/stat.h>
#include <iostream>
#include <netinet/in.h>

int main(int argc, char * argv[]) {
	if (argc < 2)
		std::cout << "give me more" << std::endl;
	struct stat s;
	std::string res;
if( stat(argv[1],&s) == 0 )
{
    if( s.st_mode & S_IFDIR )
    {
		res = "directory";
        //it's a directory
    }
    else if( s.st_mode & S_IFREG )
    {
		res = "file";
        //it's a file
    }
    else
    {
		res = "else";
        //something else
    }
}
else
{
		res = "error";
    //error
}
		std::cout << "it's a " << res << std::endl;

return 1;
}
