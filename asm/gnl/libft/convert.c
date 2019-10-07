/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:51:43 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 16:17:39 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_hexx(uintmax_t d, int a)
{
	char		*c;
	int			i;

	i = ft_numlenx(d, 16);
	c = (char*)malloc((i + 1) * sizeof(char));
	c[i--] = '\0';
	if (d != 0)
	{
		while (d > 0)
		{
			if ((d % 16) < 10)
				c[i] = '0' + (d % 16);
			else if (a == 1)
				c[i] = 'W' + (d % 16);
			else if (a == 2)
				c[i] = '7' + (d % 16);
			i--;
			d /= 16;
		}
	}
	else
		c[i] = '0';
	return (c);
}

int		ft_ns(t_printf *list, int a)
{
	int		n;

	if (list->pres > a)
	{
		if (list->field > a)
			n = list->field;
		else
			n = a;
	}
	else
	{
		if (list->field > list->pres)
			n = list->field;
		else
			n = list->pres;
	}
	return (n);
}

void	ft_str0(t_printf *list)
{
	int		n;

	n = list->field;
	if (list->flag[3] != '0')
		putn(n, ' ');
	else
		putn(n, '0');
}
