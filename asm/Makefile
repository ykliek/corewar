# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 16:23:08 by ddodukal          #+#    #+#              #
#    Updated: 2019/10/29 18:52:40 by ddodukal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

LIB = gnl/libft/libft.a

HEAD = asm.h

SRC = asm.c bonus.c checkfile.c comname.c labelch.c valid.c \
gnl/get_next_line.c addcheckfile.c convert.c usefull.c codecon.c dlc1.c \
block5.c dlc2.c cortos.c corconval.c corcode.c corcode2.c errman.c dlc3.c

OBJ := $(SRC:.c=.o)

PMLX := -L ./minilibx

MLX := -lmlx -framework OpenGL -framework AppKit

.SILENT:

all: $(NAME) $(OBJ)

$(NAME): libft
	@gcc -o $(NAME) -Wall -Werror -Wextra $(SRC) $(LIB)
	printf '\033[1;32m[ ✔ ] %s\n\033[0m' "Create binary asm"

libft:
	@make -C gnl/libft/
	printf '\033[1;32m[ ✔ ] %s\n\033[0m' "Compile lib"

clean:
	@rm -rf $(OBJ)
	@make clean -C gnl/libft/
	printf '\033[1;32m[ ✔ ] %s\n\033[0m' "All *.o were cleaned"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C gnl/libft
	printf '\033[1;32m[ ✔ ] %s\n\033[0m' "Libft.a and binary were cleaned"

re: fclean all