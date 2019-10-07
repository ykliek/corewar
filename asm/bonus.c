/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 12:12:49 by marvin            #+#    #+#             */
/*   Updated: 2019/10/06 12:12:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	errors(int n, int ln, t_asm *asm)
{
	if (n == 1)
		ft_printf("FILE NAME ERROR, CHECK USAGE!\n");
	if (n == 2)
		ft_printf("FILE ERROR!\n");
	if (n == 3)
		ft_printf("FILE EMPTY!\n");
	if (n == 4)
		ft_printf("WRONG COMMAND! LINE: %d!\n", ln);
	if (n == 5)
		ft_printf("WRONG COMMAND INPUT! LINE: %d!\n", ln);
	if (n == 6)
		ft_printf("DOUBLE COMMAND! LINE: %d!\n", ln);
	if (n == 7)
		ft_printf("NO '\n' IN END OF THE LINE: %d!\n", ln);
	if (n == 8)
		ft_printf("TOO LONG CHAMP COMMENT! LINE: %d!\n", ln);
	if (n == 9)
		ft_printf("NO CHAMPION NAME/COMMENT!\n", ln);
	if (n == 10)
		ft_printf("TOO LONG CHAMP NAME! LINE: %d!\n", ln);

	chistim(asm);
	exit(0);
}

void    flags(int n, char **s)
{
}