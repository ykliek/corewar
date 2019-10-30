/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlc2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:15:18 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/30 13:38:46 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	champput(char *s, int fd, int a)
{
	int					n;
	unsigned char		l;
	int					i;

	i = 0;
	l = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	n = 4;
	n += a - ft_strlen(s);
	while (n > 0)
	{
		write(fd, &l, 1);
		n--;
	}
}

void	init2(t_asm *asem)
{
	asem->opers[0] = "lldi\0";
	asem->opers[1] = "sti\0";
	asem->opers[2] = "fork\0";
	asem->opers[3] = "ldi\0";
	asem->opers[4] = "lld\0";
	asem->opers[5] = "lfork\0";
	asem->opers[6] = "aff\0";
	asem->opers[7] = "live\0";
	asem->opers[8] = "ld\0";
	asem->opers[9] = "st\0";
	asem->opers[10] = "add\0";
	asem->opers[11] = "sub\0";
	asem->opers[12] = "and\0";
	asem->opers[13] = "or\0";
	asem->opers[14] = "xor\0";
	asem->opers[15] = "zjmp\0";
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
	if (fnameval(av[i], asem) == 0)
		errors(1, 0, asem);
	asem->name_s = ft_strdup(av[i]);
	valid(asem, &lab);
	convert(asem, lab);
	ft_printf("\033[1;32mWriting output program to %s\n", asem->name_cor);
}

void	flags2(char **s, t_asm *asem, int i)
{
	int		j;

	j = 1;
	while (s[j])
	{
		if (s[i][j] == 'r')
		{
			asem->rev = 1;
			asem->rs = i;
		}
		else if (s[i][j] == 'h')
		{
			asem->hs = i;
			asem->help = 1;
			fhelp();
		}
		j++;
	}
}
