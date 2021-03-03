# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jujeong <jujeong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/10 14:15:26 by jujeong           #+#    #+#              #
#    Updated: 2020/08/15 16:52:50 by jujeong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = philo_three

FLAGS = -Wall -Wextra -Werror

SOURCES = ft_atoi.c ft_putnbr_fd.c ft_strlen.c ft_strcpy.c main.c \
			monitoring.c philo.c utils.c fork.c

SRCS = $(SOURCES)

OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -lpthread -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
