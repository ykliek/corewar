/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:42:58 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/29 17:54:10 by ddodukal         ###   ########.fr       */
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
	asem->name_cor[j + 4] = '\0';
	return (1);
}

void	chistim2(t_lab *lab)
{
	t_lab	*tmp;
	int		i;

	while (lab)
	{
		ft_strdel(&(lab->label));
		i = 0;
		while (i < 3)
		{
			ft_strdel(&(lab->args[i]));
			i++;
		}
		tmp = lab;
		lab = lab->next;
		free(tmp);
	}
}

void	chistim(t_asm *asem, t_lab *lab)
{
	if (asem)
	{
		ft_strdel(&(asem->name_s));
		ft_strdel(&(asem->name_cor));
		ft_strdel(&(asem->champ_com));
		ft_strdel(&(asem->champ_name));
		free(asem->opers);
		free(asem);
	}
	if (lab)
		chistim2(lab);
}

int		main(int ac, char **av)
{
	t_asm	*asem;
	t_lab	*lab;

	lab = NULL;
	asem = NULL;
	if (ac < 2 || ac > 3)
		errors(0, 0, asem);
	else
	{
		asem = ft_memalloc(sizeof(t_asm));
		init(asem);
		flags(av, asem, ac);
		if (asem->rev == 0 && asem->help == 0)
			stocor(asem, lab, av);
		else if (asem->rev == 1)
			cortos(av, asem);
	}
	return (0);
}
