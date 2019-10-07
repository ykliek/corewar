/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:36:16 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 16:17:24 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putn(int n, char c)
{
	while (n > 0)
	{
		write(1, &c, 1);
		n--;
	}
}

int		ft_lx(t_printf *list, int n, int a, int d)
{
	int		l;

	l = 0;
	if (list->pres > a)
		a = list->pres;
	if (list->flag[4] == '#' && d != 0)
		a += 2;
	l = n - a;
	return (l);
}

int		ft_lo(t_printf *list, int n, int a, int d)
{
	int		l;

	l = 0;
	if (list->flag[4] == '#' && d != 0)
		a += 1;
	if (list->pres > a)
		a = list->pres;
	l = n - a;
	return (l);
}

void	ft_hash(t_printf *list, int a, uintmax_t d)
{
	if (list->flag[4] == '#' && a == 1 && d != 0)
		write(1, "0x", 2);
	else if (list->flag[4] == '#' && a == 2 && d != 0)
		write(1, "0X", 2);
	else if (list->flag[4] == '#' && a == 3 && d != 0)
		write(1, "0", 1);
}

int		ft_nf1(t_printf *list, int a, unsigned long long *x, double d)
{
	int					n;

	n = a;
	if (d < 0 || (*x >> 63 & 1))
		n++;
	if (list->flag[2] == ' ' && (!(*x >> 63 & 1)))
		n++;
	if (list->flag[0] == '+' && (!(*x >> 63 & 1)))
		n++;
	if (list->flag[4] == '#' && list->pres == -1)
		n++;
	return (n);
}
