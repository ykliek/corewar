/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labelch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:37:15 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/22 13:09:34 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_wh1(char *file, int i)
{
	if (file[i] != '\n' && file[i] != COMMENT_CHAR
	&& file[i] != ALT_COMMENT_CHAR)
		return (1);
	return (0);
}

int		ft_skip(char *file, int i, int n)
{
	int		j;

	if (n == 1)
	{
		j = i;
		while (file[j] != SEPARATOR_CHAR && file[j] != '\n'
		&& file[j] != COMMENT_CHAR
		&& file[j] != ALT_COMMENT_CHAR && file[i] != ' ' && file[i] != '	')
			j++;
		return (j);
	}
	else
	{
		while (file[i] == ' ' || file[i] == '	')
			i++;
		return (i);
	}
}

int		argch(char *file, int i, t_lab *page)
{
	int		k;
	int		j;

	k = 0;
	j = 0;
	while (ft_wh1(file, i) == 1)
	{
		i = ft_skip(file, i, 2);
		if (file[i] == 'r')
			page->art[k] = 1;
		else if (file[i] == DIRECT_CHAR)
			page->art[k] = 2;
		else
			page->art[k] = 3;
		j = ft_skip(file, i, 1);
		page->args[k] = ft_strnew(j - i);
		ft_strncpy(page->args[k], &file[i], j - i);
		i = j;
		if (file[i] == SEPARATOR_CHAR)
		{
			k++;
			i++;
		}
	}
	return (i);
}

int		opercheck(char *file, int i, t_asm *asem, t_lab *page)
{
	int		j;

	j = 0;
	while (j < 16)
	{
		page->ln = asem->ln;
		if (ft_strstr(&file[i], asem->opers[j]) != NULL
		&& asem->opers[j][0] == file[i])
		{
			page->oper = asem->opers[j];
			break ;
		}
		j++;
	}
	i += ft_strlen(page->oper);
	i = argch(file, i, page);
	i = ft_comment(file, i);
	return (i);
}

int		labcheck(char *file, int i, t_asm *asem, t_lab *page)
{
	int		j;

	j = 0;
	while (file[i + j] != LABEL_CHAR)
		j++;
	j++;
	page->label = ft_strnew(j);
	ft_strncpy(page->label, &file[i], j);
	while (file[i] != LABEL_CHAR)
		i++;
	i++;
	while (file[i] == ' ' || file[i] == '	' || file[i] == '\n')
	{
		if (file[i] == '\n')
			asem->ln++;
		i++;
	}
	i = opercheck(file, i, asem, page);
	return (i);
}
