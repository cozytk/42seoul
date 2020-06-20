# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-alla <nel-alla@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/17 08:12:50 by nel-alla          #+#    #+#              #
#    Updated: 2020/06/21 07:43:58 by taekkim          ###   ########.fr        #
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
