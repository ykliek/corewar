# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykliek <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 13:02:57 by ykliek            #+#    #+#              #
#    Updated: 2019/10/22 18:31:16 by ykliek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../corewar

CC = gcc
CFLAGS = -Wall -Wextra -Werror -lncurses

INCLUDE_DIR = ./includes
LIBFT_DIR = ../libft
LIBFT = ../libft/libft.a
INC_COREWAR = ./includes/virtual_machine.h

SRCS = src/checker.c \
		src/commands.c \
		src/create_arena.c \
		src/cycle.c \
		src/dblst_tools.c \
		src/define.c \
		src/dump.c \
		src/error_management.c \
		src/order.c \
		src/reader.c \
		src/virtual_machine.c \
		../resources/op.c

OBJ := $(SRC:.c=.o)

all: $(NAME) $(OBJ)

$(NAME): libft
	$(CC) -o $(NAME) $(CFLAGS) $(SRCS) -I $(INC_COREWAR) $(LIBFT)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create binary corewar"

libft:
	@make -C $(LIBFT_DIR)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Compile lib"

clean:
	@rm -rf $(OBJ)
	@make clean -C $(LIBFT_DIR)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "All *.o were cleaned"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "All libft.a and binary were cleaned"

cleanlib:
	make -C $(LIBFT_DIR) clean

fcleanlib:
	make -C $(LIBFT_DIR) fclean

relib:
	make -C $(LIBFT_DIR) re

deb :
	$(CC) -lncurses -o $(NAME) $(SRCS) -I $(INC_COREWAR) $(LIBFT)

.PHONY: clean fclean re libft all
