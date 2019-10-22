# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykliek <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 17:19:06 by ykliek            #+#    #+#              #
#    Updated: 2019/10/22 17:19:11 by ykliek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@cd asm && make && mv asm ..
	@cd vm && make && mv corewar ..

clean:
	@cd asm && make clean
	@cd vm && make clean

fclean: clean
	@rm -f asm corewar && \
		echo "\033[0;36mVirtual Machine and ASM removed\033[0m"

re: fclean all

.PHONY:all clean fclean re
