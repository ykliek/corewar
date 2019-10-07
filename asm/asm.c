/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 10:37:52 by marvin            #+#    #+#             */
/*   Updated: 2019/10/06 10:37:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		fnameval(char *s, t_asm *asm)
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
	if(s[i + 1] != s || s[i + 2] != '\0')
		return (0);
	//strncpy();
	//---------
	asm->name_cor = ft_memalloc(sizeof(char) * i + 5);
	asm->name_cor[i + 4] == '\0';
	j = 0;
	while (j <= i)
	{
		asm->name_cor[j] = s[j];
		j++;
	}
	asm->name_cor[j + 1] = '.';
	asm->name_cor[j + 2] = 'c';
	asm->name_cor[j + 3] = 'o';
	asm->name_cor[j + 4] = 'r';
	//------------
}

void	init(t_asm *asm)
{
	int		i;

	i = 0;
	asm->champ_name = ft_strnew(PROG_NAME_LENGTH);
	asm->champ_com = ft_strnew(COMMENT_LENGTH);
	asm->opers = ft_memalloc(sizeof(char) * 16);
	while(i < 16)
	{
		i++;
	}
}

int     main(int ac, char **av)
{
	t_asm	*asm;
	t_lab	*lab;

	if (ac < 2)
		ft_printf("Usage: ./asm (champion_file.s | -hf)\n");
	else
	{
		asm = ft_memalloc(sizeof(t_asm));
		init(asm);
		if(ac > 2)
			flags(ac, av);
		if (fnameval(av[1], asm) == 0)
			errors(1, 0, asm);
		asm->name_s = ft_stccpy(av[1]);
		valid(asm, lab);
		convert();
		ft_printf("Writing output program to %s\n", asm->name_cor);
	}
	return (0);
}