# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykliek <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 13:02:57 by ykliek            #+#    #+#              #
#    Updated: 2019/10/08 13:03:00 by ykliek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COREWAR = ../corewar

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f
MKDIR = mkdir -p

LIBFT = -L ../libft -lft -lcurses
LIBFT_PATH = ../libft
INC_COREWAR = virtual_machine.h
SRCS = cirtual_machine.c

GREEN = \033[32m
RED = \033[31m
DEFAULT = \033[37m
CYAN = \x1b[36m
OBJS = $(SRCS:.c=.o)
VPATH = srcs/:funcs/:funcs_tests:

all:	$(COREWAR)

# Executables
$(COREWAR): $(OBJS)
	@$(CC) -o $@ $^ $(CFLAGS) -include $(INC_COREWAR) $(LIBFT)
	@echo "Compiling [$@]"

# Object files
$(OBJS): $(SRCS)
	@$(CC) -c $^ $(CFLAGS) -include $(INC_COREWAR)
	@$(ECHO)

# Cleaning rules
clean:
	@rm -f $(OBJS)
	@echo "Cleaning [$(OBJS)]"

fclean:
	@rm -f $(OBJS)
	@rm -rf $(COREWAR)
	@echo "Cleaning [libft corewar]"

re: fclean all

.PHONY: clean fclean re libft all
