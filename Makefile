CXX			= clang++
CXXFLAGS	= -std=c++98 #-Wall -Wextra -Werror

SRCS		= main.cpp
OBJS		= $(SRCS:.cpp=.o)

NAME		= http-serv

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all


.PHONY	:	all clean fclean re
