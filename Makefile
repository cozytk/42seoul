CXX			= clang++
CXXFLAGS	= -std=c++98 #-Wall -Wextra -Werror

MAIN		= main.cpp
LIBFT		= libft.cpp

CONFIG		= Config.cpp ConfigReader.cpp ConfigSyntax.cpp

SERVER		= ServerManager.cpp Server.cpp

CONNECTION	= ParsedRequest.cpp RequestInspect.cpp

CGI			= CGI.cpp

AUTOINDEX	= AutoIndex.cpp

SRCS		= $(addprefix srcs/, $(MAIN)) \
			  $(addprefix srcs/, $(LIBFT)) \
			  $(addprefix srcs/config/, $(CONFIG)) \
			  $(addprefix srcs/server/, $(SERVER)) \
			  $(addprefix srcs/connection/, $(CONNECTION)) \
			  $(addprefix srcs/, $(CGI)) \
			  $(addprefix srcs/, $(AUTOINDEX))

INCS		= incs/

OBJS		= $(SRCS:.cpp=.o)

NAME		= webserv

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS) -I$(INCS)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all


.PHONY	:	all clean fclean re
