/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:36:35 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 19:45:10 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		labcor(char c, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	initlab(t_lab *page)
{
	page->label = NULL;
	page->oper = NULL;
	page->arg1 = 0;
	page->ar1t = 0;
	page->arg2 = 0;
	page->ar2t = 0;
	page->arg3 = 0;
	page->ar3t = 0;
	page->next = NULL;
	page->prev = NULL;
}

int		block32(char *file, int i, int ln, t_asm *asem)
{
	if (file[i + 1] == 'n')
		i = comcheck_name(asem, ln, file, i);
	else if (file[i + 1] == 'c')
		i = comcheck_com(asem, ln, file, i);
	else
		errors(4, ln, asem);
	return (i);
}

void	block31(char *file, int i, t_asm *asem, t_lab *lab)
{
	int		j;
	t_lab	*page;

	while (file[i] == ' ' || file[i] == '	')
		i++;
	j = i;
	while (labcor(file[j], LABEL_CHARS) == 1)
		j++;
	page = ft_memalloc(sizeof(t_lab));
	initlab(page);
	if (file[j] == LABEL_CHAR)
		i = labcheck(file, i, asem, page);
	else
		i = opercheck(file, i, asem, page);
	ft_listadd(&lab, page, asem);
}

void	checkfile(char *file, t_asm *asem, t_lab *lab)
{
	int		i;
	int		ln;
	int		f;

	lab = NULL;
	i = -1;
	ln = 1;
	f = 0;
	while (file[++i])
	{
		i = ft_comment(file, i);
		if (file[i] == '.')
		{
			i = block32(file, i, ln, asem);
			f++;
		}
		else
		{
			if (f < 2)
				errors(9, 0, asem);
			block31(file, i, asem, lab);
		}
		if (file[i] == '\n')
			ln++;
	}
}
