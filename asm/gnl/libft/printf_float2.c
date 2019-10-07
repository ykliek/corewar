/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_float2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:51:12 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 16:17:10 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*convfloat2(uintmax_t d1, char *s, int i, int a)
{
	while (i >= 0)
	{
		if (i > 15 + a)
			s[i] = '0';
		else if (i == a)
			s[i] = '.';
		else
		{
			s[i] = (d1 % 10) + '0';
			d1 /= 10;
		}
		i--;
	}
	return (s);
}

char	*convfloat3(t_printf *list)
{
	char		*s;
	int			i;

	if (list->pres != 0)
		i = list->pres + 2;
	else
		i = 8;
	s = (char*)malloc(i + 1 * sizeof(char));
	s[i] = '\0';
	i--;
	while (i >= 0)
	{
		if (i == 1)
			s[i] = '.';
		else
			s[i] = '0';
		i--;
	}
	return (s);
}

double	convd(t_printf *list, double d)
{
	int		i;

	if (d < 0)
		d *= -1;
	i = 0;
	if (list->pres == 0)
		d *= 1000000;
	else if (list->pres > 0 && list->pres < 15)
	{
		while (i < list->pres)
		{
			d *= 10;
			i++;
		}
	}
	else if (list->pres >= 15)
	{
		while (i < 15)
		{
			d *= 10;
			i++;
		}
	}
	return (d);
}

int		conva(t_printf *list, uintmax_t d1)
{
	int		a;

	if (list->pres == 0)
		a = ft_numlen(d1) - 6;
	else if (list->pres > 0 && list->pres < 15)
		a = ft_numlen(d1) - list->pres;
	else if (list->pres >= 15)
		a = ft_numlen(d1) - 15;
	else
		a = ft_numlen(d1);
	if (d1 == 0)
		a = 1;
	return (a);
}

char	*convfloat(double d, t_printf *list)
{
	char		*s;
	uintmax_t	d1;
	int			i;
	int			a;
	int			n;

	a = 0;
	if (d == 0)
		return (convfloat3(list));
	d = convd(list, d);
	d1 = d;
	n = (d - d1) * 10;
	if (n > 5)
		d1++;
	a = conva(list, d1);
	if (list->pres == 0)
		i = a + 6 + 1;
	else
		i = a + list->pres + 1;
	s = (char*)malloc(i + 1 * sizeof(char));
	s[i--] = '\0';
	return (convfloat2(d1, s, i, a));
}
