/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labelch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:37:15 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 17:45:30 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		opercheck(char *file, int i, t_asm *asem, t_lab *page)
{
	(void)file;
	(void)asem;
	(void)page;
	return (i);
}

int		labcheck(char *file, int i, t_asm *asem, t_lab *page)
{
	int		j;

	j = 0;
	while (file[i + j] != LABEL_CHAR)
		j++;
	ft_strncpy(page->label, &file[i], j);
	i += (j + 1);
	while (file[i] == ' ' || file[i] == '	')
		i++;
	i = opercheck(file, i, asem, page);
	return (i);
}
