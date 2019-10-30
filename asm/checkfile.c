/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:36:35 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/30 13:35:27 by ddodukal         ###   ########.fr       */
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
	page->art[0] = 0;
	page->art[1] = 0;
	page->art[2] = 0;
	page->args = ft_memalloc(sizeof(char*) * 3);
	page->len = 0;
	page->ln = 0;
	page->code = NULL;
	page->next = NULL;
	page->prev = NULL;
	page->opc = 0;
}

int		block32(char *file, int i, t_asm *asem)
{
	if (file[i + 1] == 'n')
		i = comcheck_name(asem, file, i);
	else if (file[i + 1] == 'c')
		i = comcheck_com(asem, file, i);
	else
		errors(4, asem->ln, asem);
	return (i);
}

int		block31(char *file, int i, t_asm *asem, t_lab **lab)
{
	int		j;
	t_lab	*page;

	while (file[i] == ' ' || file[i] == '	' || file[i] == '\n')
	{
		if (file[i] == '\n')
			asem->ln++;
		i++;
	}
	j = i;
	while (labcor(file[j], LABEL_CHARS) == 1)
		j++;
	page = ft_memalloc(sizeof(t_lab));
	initlab(page);
	if (file[j] == LABEL_CHAR)
		i = labcheck(file, i, asem, page);
	else
		i = opercheck(file, i, asem, page);
	ft_listadd(lab, page, asem);
	return (i);
}

void	checkfile(char *file, t_asm *asem, t_lab **lab)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	while (file[i])
	{
		i = ft_comment(file, i);
		if (ft_strlen(&file[i]) == 0)
			break ;
		if (file[i] == '.')
		{
			i = block32(file, i, asem);
			f++;
		}
		else if (file[i] != '\n')
		{
			chforerr(file, i, asem, f);
			i = block31(file, i, asem, lab);
		}
		i = gendalf(file, i, asem);
	}
	ft_strdel(&file);
}
