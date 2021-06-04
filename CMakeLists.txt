cmake_minimum_required(VERSION 3.19)
project(webserv)

set(CMAKE_CXX_STANDARD 98)

include_directories(incs)

add_executable(webserv
        incs/AutoIndex.hpp
        incs/CGI.hpp
        incs/Config.hpp
        incs/ConfigReader.hpp
        incs/ConfigSyntax.hpp
        incs/ParsedRequest.hpp
        incs/RequestConfig.hpp
        incs/RequestInspect.hpp
        incs/Server.hpp
        incs/ServerManager.hpp
        incs/webserv.hpp
        incs/WebServerConstant.hpp
        srcs/config/Config.cpp
        srcs/config/ConfigReader.cpp
        srcs/config/ConfigSyntax.cpp
        srcs/connection/ParsedRequest.cpp
        srcs/connection/RequestConfig.cpp
        srcs/connection/RequestInspect.cpp
        srcs/server/Server.cpp
        srcs/server/ServerManager.cpp
        srcs/AutoIndex.cpp
        srcs/CGI.cpp
        srcs/libft.cpp
        srcs/main.cpp)
