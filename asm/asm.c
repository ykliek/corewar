/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:42:58 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 19:38:27 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		fnameval(char *s, t_asm *asem)
{
	int		i;
	int		j;

	i = 0;
	while (s[i])
		i++;
	while (s[i] != '.' && i >= 0)
		i--;
	if (i <= 0)
		return (0);
	if (s[i + 1] != 's' || s[i + 2] != '\0')
		return (0);
	asem->name_cor = ft_memalloc(sizeof(char) * i + 4);
	ft_strncpy(asem->name_cor, s, i + 1);
	j = i;
	asem->name_cor[j + 1] = 'c';
	asem->name_cor[j + 2] = 'o';
	asem->name_cor[j + 3] = 'r';
	return (1);
}

void	init(t_asm *asem)
{
	int		i;

	i = 0;
	asem->champ_name = ft_strnew(PROG_NAME_LENGTH);
	asem->champ_com = ft_strnew(COMMENT_LENGTH);
	asem->opers = ft_memalloc(sizeof(char*) * 16);
	asem->opers[0] = "live";
	asem->opers[1] = "ld";
	asem->opers[2] = "st";
	asem->opers[3] = "add";
	asem->opers[4] = "sub";
	asem->opers[5] = "and";
	asem->opers[6] = "or";
	asem->opers[7] = "xor";
	asem->opers[8] = "zjmp";
	asem->opers[9] = "ldi";
	asem->opers[10] = "sti";
	asem->opers[11] = "fork";
	asem->opers[12] = "lld";
	asem->opers[13] = "lldi";
	asem->opers[14] = "lfork";
	asem->opers[15] = "aff";
}

void	chistim(t_asm *asem)
{
	(void)asem;
}

int		main(int ac, char **av)
{
	t_asm	*asem;
	t_lab	*lab;

	lab = NULL;
	if (ac < 2)
	{
		ft_printf("Usage: ./asem (champion_file.s");
		ft_printf("| -r binary_file.cor | -hf)\n");
	}
	else
	{
		asem = ft_memalloc(sizeof(t_asm));
		init(asem);
		if (ac > 2)
			flags(ac, av);
		if (fnameval(av[1], asem) == 0)
			errors(1, 0, asem);
		asem->name_s = ft_strdup(av[1]);
		valid(asem, lab);
		ft_printf("Writing output program to %s\n", asem->name_cor);
	}
	return (0);
}
