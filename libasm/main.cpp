#include <fcntl.h>
#include <unistd.h>
#include <iostream>

int main()
{
    int fd;

    fd = open("nanana", O_CREAT|O_WRONLY, 0777);
    std::cout << fd << std::endl;
    std::cout << write(fd, "Hello World\n", 12) << std::endl;
    return (0);
}
//
// Created by Taekyun Kim on 6/23/21.
//

