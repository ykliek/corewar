/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errman.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:03:25 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/29 17:20:59 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	errman2(int n)
{
	if (n == 7)
		write(2, "NO '\\n' IN END OF FILE\n", 23);
	else if (n == 8)
		write(2, "TOO LONG CHAMP COMMENT! LINE: ", 30);
	else if (n == 9)
		write(2, "NO CHAMPION NAME/COMMENT!\n", 26);
	else if (n == 10)
		write(2, "TOO LONG CHAMP NAME! LINE: ", 27);
	else if (n == 11)
		write(2, "TOO LONG CHAMP COMM! LINE: ", 27);
	else if (n == 12)
		write(2, "ARGS NUMM ERROR! LINE: ", 23);
	else if (n == 13)
		write(2, "FLAG ERROR!\n", 12);
}

void	errman(int n)
{
	if (n == 0)
	{
		ft_printf("\033[1;32mUsage: ./asem (-h | champion_file.s");
		ft_printf("\033[1;32m | -r binary_file.cor)\n");
	}
	else if (n == 1)
		write(2, "FILE NAME ERROR, CHECK USAGE!\n", 30);
	else if (n == 2)
		write(2, "FILE ERROR!\n", 12);
	else if (n == 3)
		write(2, "FILE EMPTY!\n", 12);
	else if (n == 4)
		write(2, "WRONG COMMAND! LINE: ", 21);
	else if (n == 5)
		write(2, "WRONG COMMAND INPUT! LINE: ", 27);
	else if (n == 6)
		write(2, "DOUBLE COMMAND! LINE: ", 22);
	else
		errman2(n);
}
