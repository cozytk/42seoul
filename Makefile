NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c -I$(INC_PATH)

SRC_PATH = ./srcs
LIB_PATH = ./lib
INC_PATH = ./include
OBJ_PATH = ./obj
OBJLIB_PATH = ./obj

SRC_NAME = ft_printf.c \
		print.c \
		print2.c \
		set.c \
		initialize.c \
		hexical.c \
		confirm.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = util.c \
		util2.c
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/, $(OBJLIB_NAME))

all : $(NAME)

$(NAME) : $(OBJ) $(OBJLIB)
	@ar rcs $(NAME) $(OBJ) $(OBJLIB)
	@ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ) $(OBJLIB)

fclean: clean
	@rm -rf ./obj $(NAME)

re: fclean all

norme:
	@norminette $(SRC) $(LIB) $(INC)

.PHONY: all clean fclean re norm