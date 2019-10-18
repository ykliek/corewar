/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlc2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:15:18 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/18 19:46:19 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init2(t_asm *asem)
{
	asem->opers[0] = "ldi";
	asem->opers[1] = "sti";
	asem->opers[2] = "fork";
	asem->opers[3] = "lld";
	asem->opers[4] = "lldi";
	asem->opers[5] = "lfork";
	asem->opers[6] = "aff";
	asem->opers[7] = "live";
	asem->opers[8] = "ld";
	asem->opers[9] = "st";
	asem->opers[10] = "add";
	asem->opers[11] = "sub";
	asem->opers[12] = "and";
	asem->opers[13] = "or";
	asem->opers[14] = "xor";
	asem->opers[15] = "zjmp";
}

void	init(t_asm *asem)
{
	int		i;

	i = 0;
	asem->champ_name = ft_strnew(PROG_NAME_LENGTH);
	asem->champ_com = ft_strnew(COMMENT_LENGTH);
	asem->ln = 1;
	asem->opers = ft_memalloc(sizeof(char*) * 16);
	asem->code = NULL;
	asem->magic = 0xea83f3;
	asem->rev = 0;
	asem->help = 0;
	asem->hs = 0;
	init2(asem);
}

void	stocor(t_asm *asem, t_lab *lab, char **av)
{
	int		i;

	i = 1;
	if (asem->help == 1 && asem->hs == 1)
		i = 2;
	if (av[i])
	{
		if (i == 2)
			ft_printf("\n");
		if (fnameval(av[i], asem) == 0)
			errors(1, 0, asem);
		asem->name_s = ft_strdup(av[i]);
		valid(asem, &lab);
		convert(asem, lab);
		ft_printf("\033[1;32mWriting output program to %s\n", asem->name_cor);
	}
}
