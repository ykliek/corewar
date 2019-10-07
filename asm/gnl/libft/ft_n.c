/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:58:58 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 16:17:33 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_no(t_printf *list, int a, uintmax_t d)
{
	int		n;

	if (list->flag[4] == '#' && d != 0)
		a += 1;
	if (list->pres > a)
		a = list->pres;
	if (list->field != 0 && list->field > a)
		n = list->field;
	else
		n = a;
	return (n);
}

int		ft_nx(t_printf *list, int a, uintmax_t d)
{
	int		n;

	if (list->pres >= a)
		a = list->pres;
	if (list->flag[4] == '#' && d != 0)
		a += 2;
	if (list->field != 0 && list->field > a)
		n = list->field;
	else
		n = a;
	return (n);
}

int		ft_nd(t_printf *list, int a, intmax_t d)
{
	int		n;

	if (d < 0)
		a++;
	if (list->flag[0] == '+' && d >= 0)
		a += 1;
	if (list->flag[2] == ' ' && d >= 0)
		a += 1;
	if (list->pres >= a)
	{
		a = list->pres;
		if (list->flag[0] == '+' && d >= 0)
			a += 1;
		if (list->flag[2] == ' ' && d >= 0)
			a += 1;
		if (d < 0)
			a++;
	}
	if (list->field != 0 && list->field > a)
		n = list->field;
	else
		n = a;
	return (n);
}

int		ft_nu(t_printf *list, int a)
{
	int		n;

	if (list->pres > a)
		a = list->pres;
	if (list->field != 0 && list->field > a)
		n = list->field;
	else
		n = a;
	return (n);
}

int		ft_nf(t_printf *list, int a, double d)
{
	int					n;
	unsigned long long	*x;

	x = (unsigned long long *)&d;
	if (list->field == 0 || list->field < a)
		n = ft_nf1(list, a, x, d);
	else
	{
		n = list->field;
		if (list->flag[2] == ' ' && (a >= list->field) && (!(*x >> 63 & 1)))
			n++;
		if (list->flag[0] == '+' && (a >= list->field) && (!(*x >> 63 & 1)))
			n++;
		if (list->flag[4] == '#' && list->pres == -1 && (a >= list->field))
			n++;
	}
	return (n);
}
