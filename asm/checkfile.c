/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:36:35 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 18:26:10 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_listadd(t_lab **lab, t_lab *page, t_asm *asem)
{
	if (!(*lab))
	{
		(*lab) = page;
		asem->lab = (*lab);
	}
	else
	{
		while ((*lab)->next)
			(*lab) = (*lab)->next;
		(*lab)->next = page;
		page->prev = (*lab);
		page->next = NULL;
	}
}

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

int		ft_comment(char *file, int i)
{
	if (file[i] == COMMENT_CHAR || file[i] == ALT_COMMENT_CHAR)
	{
		while (file[i] != '\n')
			i++;
	}
	return (i);
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

void	checkfile(char *file, t_asm *asem, t_lab *lab)
{
	int		i;
	int		ln;
	int		j;
	int		f;
	t_lab	*page;

	lab = NULL;
	i = 0;
	ln = 1;
	f = 0;
	while (file[i])
	{
		i = ft_comment(file, i);
		if (file[i] == '.')
		{
			if (file[i + 1] == 'n')
				i = comcheck_name(asem, ln, file, i);
			else if (file[i + 1] == 'c')
				i = comcheck_com(asem, ln, file, i);
			else
				errors(4, ln, asem);
			f++;
		}
		else
		{
			if (f < 2)
				errors(9, 0, asem);
			j = i;
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
		if (file[i] == '\n')
			ln++;
		i++;
	}
}
