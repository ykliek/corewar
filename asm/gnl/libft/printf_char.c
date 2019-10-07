/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:07:44 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 16:15:32 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_char2(int l, t_printf *list, char c)
{
	if ((list->flag)[1] == '-')
	{
		write(1, &c, 1);
		putn(l, ' ');
	}
	else if ((list->flag)[3] == '0')
	{
		putn(l, '0');
		write(1, &c, 1);
	}
	else
	{
		putn(l, ' ');
		write(1, &c, 1);
	}
}

int		ft_char(char c, t_printf *list)
{
	int		n;
	int		l;

	if (list->field == 0)
	{
		write(1, &c, 1);
		n = 1;
	}
	else
	{
		n = list->field;
		l = n - 1;
		ft_char2(l, list, c);
	}
	return (n);
}
