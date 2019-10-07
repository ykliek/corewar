/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:15:22 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 16:13:35 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_flags(char c, t_printf **list)
{
	if (c == '+')
	{
		((*list)->flag)[0] = '+';
		((*list)->flag)[2] = '\0';
	}
	if (c == '-')
	{
		((*list)->flag)[1] = '-';
		((*list)->flag)[3] = '\0';
	}
	if (c == ' ' && ((char)(*list)->flag[0]) != '+')
		((*list)->flag)[2] = ' ';
	if (c == '0')
		((*list)->flag)[3] = '0';
	if (c == '#')
		((*list)->flag)[4] = '#';
}

int		ft_f(const char *format, int i)
{
	if (format[i] != '%' && format[i] != 'c' && format[i] != 's'
	&& format[i] != 'd' && format[i] != 'i' && format[i] != 'o'
	&& format[i] != 'x' && format[i] != 'X' && format[i] != 'u'
	&& format[i] != 'f' && format[i] != 'p' && format[i] != 'D'
	&& format[i] != 'U' && format[i] != 'O' && format[i] != 'F'
	&& format[i])
		return (1);
	return (0);
}

int		ft_wh2(const char *format, int i, t_printf **list)
{
	int		a;
	int		b;

	ft_flags(format[i], list);
	a = (*list)->num;
	i = ft_modif(format, i, list);
	b = (*list)->num;
	if (b < a)
		(*list)->num = a;
	return (i);
}

int		ft_format(const char *format, int i, t_printf **list)
{
	int		f;

	f = 0;
	ft_clean(list);
	while (ft_f(format, i) == 1)
	{
		i = ft_wh2(format, i, list);
		if (ft_check(format[i]) == 0)
			break ;
		if (format[i] >= '1' && format[i] <= '9' && f == 0)
		{
			f = 1;
			i = ft_field(i, list, format);
		}
		if (format[i] == '.')
		{
			f = 2;
			i = ft_pres(format, i, list);
		}
		i++;
	}
	return (i);
}
