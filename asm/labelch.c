/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labelch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:37:15 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/08 15:35:29 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		opercheck(char *file, int i, t_asm *asem, t_lab *page)
{
	int		j;
	int		k;

	k = 0;
	j = 0;
	while (j < 16)
	{
		if (ft_strstr(&file[i], asem->opers[j]) != NULL && asem->opers[j][0] == file[i])
		{
			page->oper = asem->opers[j];
			break ;
		}
		j++;
	}
	i += ft_strlen(page->oper);
	while (file[i] != '\n' && file[i] != COMMENT_CHAR && file[i] != ALT_COMMENT_CHAR)
	{
		while (file[i] == ' ' || file[i] == '	')
			i++;
		if (file[i] == 'r')
			page->art[k] = 1;
		else if (file[i] == DIRECT_CHAR)
			page->art[k] = 2;
		else
			page->art[k] = 3;
		j = i;
		while (file[j] != SEPARATOR_CHAR && file[j] != '\n' && file[j] != COMMENT_CHAR && file[j] != ALT_COMMENT_CHAR && file[i] != ' ' && file[i] != '	') 
			j++;
		page->args[k] = ft_strnew(j - i);
		ft_strncpy(page->args[k], &file[i], j - i);
		i = j;
		if (file[i] == SEPARATOR_CHAR)
		{
			k++;
			i++;
		}
	}
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
