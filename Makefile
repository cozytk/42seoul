# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taekkim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/24 00:56:20 by taekkim           #+#    #+#              #
#    Updated: 2020/07/24 00:56:28 by taekkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	ft_printf.c \
		srcs/confirm.c \
		srcs/hexical.c \
		srcs/initialize.c \
		srcs/print.c \
		srcs/print2.c \
		srcs/set.c \
		utils/util2.c \
		utils/util.c

OBJECTS = ft_printf.o \
		confirm.o \
		hexical.o \
		initialize.o \
		print.o \
		print2.o \
		set.o \
		util.o \
		util2.o

INCLUDES = inc/ft_printf.h


all: $(NAME)

$(NAME): $(OBJECTS)

$(OBJECTS): $(SRCS) $(INCLUDES)
	@gcc -Wextra -Werror -Wall -c $(SRCS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all
bonus:
