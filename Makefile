# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taekkim </var/mail/taekkim>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/19 01:35:01 by taekkim           #+#    #+#              #
#    Updated: 2020/04/19 02:14:35 by taekkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft.a

SRCS		= ft_printf.c\

OBJS		= $(SRCS:.c=.o)
CC			= gcc
CFLAGS		= -Wextra -Wall -Werror -I.
RM			= rm -f
LIBC		= ar rcs

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : #(OBJS)
	$@ -C libft/
	cp libft/$(LIBFT) $@

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJS)

re : fclean all

.PHONY: all bonus clean fclean re

