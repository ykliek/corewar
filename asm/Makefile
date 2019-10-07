# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 16:23:08 by ddodukal          #+#    #+#              #
#    Updated: 2019/10/07 16:58:54 by ddodukal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

LIB = gnl/libft/libft.a

HEAD = asm.h

SRC = asm.c bonus.c checkfile.c comname.c labelch.c valid.c \
gnl/get_next_line.c

OBJ := $(SRC:.c=.o)

PMLX := -L ./minilibx

MLX := -lmlx -framework OpenGL -framework AppKit

.SILENT:

all: $(NAME) $(OBJ)

$(NAME): libft
	@gcc -o $(NAME) -Wall -Werror -Wextra $(SRC) -I $(HEAD) $(LIB)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create binary asm"

libft:
	@make -C gnl/libft/

clean:
	@rm -rf $(OBJ)
	@make clean -C gnl/libft/

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C gnl/libft/

re: fclean all