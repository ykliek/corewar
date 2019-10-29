/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addcheckfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:44:35 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/22 14:41:30 by ddodukal         ###   ########.fr       */
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

int		ft_comment(char *file, int i)
{
	while (file[i] == ' ' || file[i] == '	')
		i++;
	if (file[i] == COMMENT_CHAR || file[i] == ALT_COMMENT_CHAR)
	{
		while (file[i] && file[i] != '\n')
			i++;
	}
	return (i);
}
