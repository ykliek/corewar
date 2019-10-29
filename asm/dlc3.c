/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlc3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:50:42 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/29 21:27:11 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	extrarg(t_asm *asem, char *s, int n)
{
	int		i;

	i = 1;
	n = 0;
	if (s[1] == ':')
		i++;
	while (s[i])
	{
		if (s[i] == '0' && s[i + 1] && s[i + 1] == 'x')
			errors(14, asem->ln, asem);
		if (s[i] == '+' || s[i] == '-' & i != 1)
			errors(14, asem->ln, asem);
		i++;
	}
}

int		chifoper(t_asm *asem, char *file, int i)
{
	int		j;

	j = i;
	while (file[j] < 65 || file[j] > 90 & file[j] < 97 || file[j] > 122)
	{
		if (file[j] == '\0')
			return (0);
		if (file[j] == '#')
			j += ft_comment(file, j);
		if (file[j] == '\n')
			asem->ln++;
		j++;
		if (!file[j])
			return (0);
	}
	while (file[j] >= 65 & file[j] <= 90 || file[j] >= 97 & file[j] <= 122)
		j++;
	if (file[j] == ':')
		return (0);
	return (1);
}

void	argch2(char *file, int i, t_lab *page, int k)
{
	if (file[i] == 'r')
		page->art[k] = 1;
	else if (file[i] == DIRECT_CHAR)
		page->art[k] = 2;
	else
		page->art[k] = 3;
}
