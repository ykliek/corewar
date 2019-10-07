/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:06:30 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 16:17:16 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_float31(t_printf *list, unsigned long long *x, char *s, int l)
{
	putn(l, ' ');
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

void	ft_float32(t_printf *list, unsigned long long *x, char *s, int l)
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
	putn(l, ' ');
}

void	ft_float33(t_printf *list, unsigned long long *x, char *s, int l)
{
	if (list->flag[2] == ' ' && (!(*x >> 63 & 1)))
		write(1, " ", 1);
	if ((list->flag)[0] == '+' && (!(*x >> 63 & 1)))
		write(1, "+", 1);
	if ((*x >> 63 & 1))
		write(1, "-", 1);
	putn(l, '0');
	ft_putstr(s);
	if (list->flag[4] == '#' && list->pres == -1)
		write(1, ".", 1);
}

void	ft_float3(t_printf *list, unsigned long long *x, char *s, int n)
{
	int		l;

	l = n - ft_strlen(s);
	if ((*x >> 63 & 1))
		l--;
	if ((list->flag)[0] == '+' && (!(*x >> 63 & 1)))
		l--;
	if (list->flag[2] == ' ' && (!(*x >> 63 & 1)))
		l--;
	if (list->flag[4] == '#' && list->pres == -1)
		l--;
	if ((list->flag)[1] != '-' && (list->flag)[3] != '0')
		ft_float31(list, x, s, l);
	if ((list->flag)[1] == '-')
		ft_float32(list, x, s, l);
	if ((list->flag)[3] == '0')
		ft_float33(list, x, s, l);
}

int		ft_float(double d, t_printf *list)
{
	int					n;
	char				*s;
	unsigned long long	*x;

	x = (unsigned long long *)&d;
	s = convfloat(d, list);
	n = ft_nf(list, ft_strlen(s), d);
	if (list->pres == -1 && d == 0)
		return (ft_float2(list, x));
	if ((d == 1.0 / 0.0) || (d == -1.0 / 0.0) || d != d)
		return (ft_float1(list, d, list->field, s));
	if (list->field == 0 || (list->field <= list->pres && list->pres != 0)
	|| (list->field < (int)ft_strlen(s) && list->pres == 0))
		ft_float4(list, x, s);
	else
		ft_float3(list, x, s, n);
	return (n);
	free(s);
}
