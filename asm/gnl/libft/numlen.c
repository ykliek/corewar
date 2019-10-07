/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:23:38 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 16:16:54 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen(intmax_t d)
{
	int		n;

	n = 0;
	if (d > 0)
	{
		while (d > 0)
		{
			n++;
			d /= 10;
		}
	}
	else if (d < 0)
	{
		n++;
		while (d < 0)
		{
			n++;
			d /= 10;
		}
	}
	else
		return (1);
	return (n);
}

int		ft_numlent(uintmax_t d)
{
	int		l;

	l = 0;
	if (d == 0)
		return (1);
	else
	{
		while (d > 0)
		{
			l++;
			d /= 10;
		}
	}
	return (l);
}

int		ft_numlenx(uintmax_t d, int a)
{
	int		i;

	i = 0;
	if (d != 0)
	{
		while (d > 0)
		{
			d /= a;
			i++;
		}
	}
	else
		return (1);
	return (i);
}
