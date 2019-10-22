#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/03 22:21:07 by eamielin          #+#    #+#              #
#    Updated: 2018/11/03 22:21:08 by eamielin         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= libft.a

OBJ_DIR		= ./objects/
INC_DIR		= .

FLAGS		= -Wall -Werror -Wextra
HEADER_FLAGS	= -I $(INC_DIR)

C_FILES		= ft_arrlst.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_contdel.c \
		ft_donothing.c \
		ft_elemnewdeterm.c \
		ft_elemnewterm.c \
		ft_elemnuldeterm.c \
		ft_elemnulterm.c \
		ft_error.c \
		ft_findchr.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_ishex.c \
		ft_fittoint.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstaddafter.c \
		ft_lstaddend.c \
		ft_lstarr.c \
		ft_lstcat.c \
		ft_lstcount.c \
		ft_lstdel.c \
		ft_lstdelcount.c \
		ft_lstdelone.c \
		ft_lstinter.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstmaxsize.c \
		ft_lstnew.c \
		ft_lstsave.c \
		ft_lstprint.c \
		ft_lstpushend.c \
		ft_lstrvr.c \
		ft_lstsize.c \
		ft_lstskip.c \
		ft_lstterm.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_onlyatoistr.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_qfree.c \
		ft_split.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_capitalizer.c \
		get_next_line.c \
		ft_itoa_base.c \
		ft_atoi_base.c \
		ed_memalloc.c

O_FILES		= $(addprefix $(OBJ_DIR), $(C_FILES:.c=.o))

all: $(NAME)

$(NAME): $(O_FILES)
	ar rc $(NAME) $(O_FILES)
	ranlib $(NAME)

$(O_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
		gcc -c $< -o $@ $(FLAGS) $(HEADER_FLAGS)

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)
	rm -Rf $(OBJ_DIR)

re: fclean all
