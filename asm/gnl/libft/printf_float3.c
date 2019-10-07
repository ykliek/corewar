/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_float3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:29:51 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 16:17:12 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_float11(t_printf *list, int n, char *s)
{
	s = "inf";
	if (list->flag[0] == '+')
		n--;
	if (list->flag[1] != '-')
	{
		putn(n - 3, ' ');
		if (list->flag[0] == '+')
			write(1, "+", 1);
		ft_putstr(s);
	}
	else
	{
		if (list->flag[2] == ' ')
		{
			n--;
			write(1, " ", 1);
		}
		if (list->flag[0] == '+')
			write(1, "+", 1);
		ft_putstr(s);
		putn(n - 3, ' ');
	}
}

void	ft_float12(t_printf *list, int n, char *s)
{
	s = "-inf";
	if (list->flag[1] != '-')
	{
		putn(n - 4, ' ');
		ft_putstr(s);
	}
	else
	{
		ft_putstr(s);
		putn(n - 4, ' ');
	}
}

int		ft_float1(t_printf *list, double d, int n, char *s)
{
	if (d == 1.0 / 0.0)
		ft_float11(list, n, s);
	else if (d == -1.0 / 0.0)
		ft_float12(list, n, s);
	else if (d != d)
	{
		s = "nan";
		if (list->flag[1] != '-')
		{
			putn(n - 3, ' ');
			ft_putstr(s);
		}
		else
		{
			ft_putstr(s);
			putn(n - 3, ' ');
		}
	}
	return (list->field);
}

int		ft_float2(t_printf *list, unsigned long long *x)
{
	int		a;

	a = 1;
	if (list->flag[0] == '+' && (!(*x >> 63 & 1)))
		a++;
	if (list->flag[4] == '#')
		a++;
	if (list->flag[2] == ' ' && (!(*x >> 63 & 1)))
	{
		a++;
		write(1, " ", 1);
	}
	putn(list->field - a, ' ');
	if (list->flag[0] == '+' && (!(*x >> 63 & 1)))
		write(1, "+", 1);
	write(1, "0", 1);
	if (list->flag[4] == '#')
		write(1, ".", 1);
	if (list->field != 0)
		return (list->field);
	else
		return (a);
}

void	ft_float4(t_printf *list, unsigned long long *x, char *s)
{
	if (list->flag[2] == ' ' && (!(*x >> 63 & 1)))
		write(1, " ", 1);
	if ((list->flag)[0] == '+' && (!(*x >> 63 & 1)))
		write(1, "+", 1);
	if ((*x >> 63 & 1))
		write(1, "-", 1);
	ft_putstr(s);
	if (list->flag[4] == '#' && list->pres == -1)
		write(1, ".", 1);
}
