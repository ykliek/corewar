/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_num2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:57:46 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 16:14:48 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_num11(t_printf *list)
{
	int		n;

	n = 0;
	if (list->field != 0 && list->flag[0] == '+')
		n = list->field - 1;
	else if (list->field != 0 && list->flag[0] != '+')
		n = list->field;
	else if (list->field == 0 && list->flag[0] == '+')
		n = 1;
	else if (list->field == 0 && list->flag[0] != '+')
	{
		if (list->flag[2] == ' ')
			n = 1;
		else
			n = 0;
	}
	return (n);
}

int		ft_num1(t_printf *list)
{
	int		n;
	int		a;

	n = ft_num11(list);
	if (list->flag[0] == '+')
		a = n - 1;
	else
		a = n;
	if (list->flag[1] == '-')
	{
		if (list->flag[0] == '+')
			write(1, "+", 1);
		putn(a, ' ');
	}
	else
	{
		putn(a, ' ');
		if (list->flag[0] == '+')
			write(1, "+", 1);
	}
	return (n);
}

void	ft_num31(t_printf *list, char *s, intmax_t d, int l)
{
	if ((list->flag)[1] == '-')
	{
		if (list->flag[0] == '+' && d >= 0)
			write(1, "+", 1);
		if (list->flag[2] == ' ' && d >= 0)
			write(1, " ", 1);
		if (d < 0)
			write(1, "-", 1);
		ft_putstr(s);
		putn(l, ' ');
	}
	else if ((list->flag)[3] == '0')
	{
		if (list->flag[0] == '+' && d >= 0)
			write(1, "+", 1);
		if (list->flag[2] == ' ' && d >= 0)
			write(1, " ", 1);
		if (d < 0)
			write(1, "-", 1);
		putn(l, '0');
		ft_putstr(s);
	}
}

void	ft_num3(t_printf *list, char *s, intmax_t d, int n)
{
	int		l;

	l = n - ft_strlen(s);
	if ((list->flag)[0] == '+' && d >= 0)
		l--;
	if (list->flag[2] == ' ')
		l--;
	if (d < 0)
		l--;
	if ((list->flag)[1] != '-' && (list->flag)[3] != '0')
	{
		putn(l, ' ');
		if (list->flag[0] == '+' && d >= 0)
			write(1, "+", 1);
		if (list->flag[2] == ' ' && d >= 0)
			write(1, " ", 1);
		if (d < 0)
			write(1, "-", 1);
		ft_putstr(s);
	}
	else
		ft_num31(list, s, d, l);
}

void	ft_num2(t_printf *list, intmax_t d, char *s)
{
	int		l;

	if (list->pres == 0)
	{
		if (d < 0)
			write(1, "-", 1);
		if (list->flag[0] == '+' && d >= 0)
			write(1, "+", 1);
		if (list->flag[2] == ' ' && d >= 0)
			write(1, " ", 1);
		ft_putstr(s);
	}
	else
	{
		l = list->pres - ft_strlen(s);
		if (list->flag[2] == ' ' && d >= 0)
			write(1, " ", 1);
		if (list->flag[0] == '+' && d >= 0)
			write(1, "+", 1);
		if (d < 0)
			write(1, "-", 1);
		putn(l, '0');
		ft_putstr(s);
	}
}
