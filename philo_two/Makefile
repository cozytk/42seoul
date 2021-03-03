# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taekkim <taekkim@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/03 16:08:30 by taekkim           #+#    #+#              #
#    Updated: 2021/03/03 16:08:32 by taekkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = philo_two

FLAGS = -Wall -Wextra -Werror

SOURCES = ft_atoi.c ft_putnbr_fd.c ft_strlen.c main.c \
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
