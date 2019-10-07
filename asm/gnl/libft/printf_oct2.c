/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_oct2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:25:22 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 16:14:54 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_octal11(t_printf *list)
{
	int		n;

	n = 0;
	if (list->field != 0 && list->flag[4] == '#')
		n = list->field - 1;
	else if (list->field != 0 && list->flag[4] != '#')
		n = list->field;
	else if (list->field == 0 && list->flag[4] == '#')
		n = 1;
	else if (list->field == 0 && list->flag[4] != '#')
		n = 0;
	return (n);
}

int		ft_octal1(t_printf *list)
{
	int		n;
	int		a;

	n = ft_octal11(list);
	if (list->flag[4] == '#')
		a = n - 1;
	else
		a = n;
	if (list->flag[1] == '-')
	{
		if (list->flag[4] == '#')
			write(1, "0", 1);
		putn(a, ' ');
	}
	else
	{
		putn(a, ' ');
		if (list->flag[4] == '#')
			write(1, "0", 1);
	}
	return (n);
}
