# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 08:21:33 by ddodukal          #+#    #+#              #
#    Updated: 2019/10/07 18:16:26 by ddodukal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEAD = includes/libft.h

SRC = ft_memset.c ft_bzero.c ft_memccpy.c ft_memcpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
	ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
	ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_sqr.c ft_sqrt.c ft_fact.c \
	ft_prime.c ft_abs.c ft_words.c ft_strndup.c ft_putstr.c ft_putnbr.c \
	ft_putchar.c struct.c ft_atoi.c ft_strlen.c format.c printf_hex.c \
	printf_oct.c  printf_str.c printf_char.c printf_uns.c \
	printf_float.c printf_point.c length.c numlen.c more.c printf_float2.c \
	printf.c addition.c printf_num.c ft_n.c convert.c printf_oct2.c \
	printf_num2.c printf_float3.c

OBJ = $(SRC:.c=.o)

.SILENT:

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	@gcc -c -Wall -Werror -Wextra -I $(HEAD) $(SRC)
	@ar -rv $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
