/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:07:58 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 16:14:23 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hex1(t_printf *list)
{
	int		n;

	n = 0;
	if (list->field != 0)
		n = list->field;
	else
		n = 0;
	putn(n, ' ');
	return (n);
}

void	ft_hex3(t_printf *list, char *c, uintmax_t d, int a)
{
	int		p;
	int		l;
	int		n;

	n = ft_nx(list, ft_strlen(c), d);
	p = list->pres;
	l = ft_lx(list, n, ft_strlen(c), d);
	p -= ft_strlen(c);
	if ((list->flag)[1] != '-')
	{
		putn(l, ' ');
		ft_hash(list, a, d);
		putn(p, '0');
		ft_putstr(c);
	}
	else
	{
		ft_hash(list, a, d);
		putn(p, '0');
		ft_putstr(c);
		putn(l, ' ');
	}
}

void	ft_hex4(t_printf *list, char *c, uintmax_t d, int a)
{
	int		l;

	l = list->field - ft_strlen(c);
	if ((list->flag)[4] == '#' && d != 0)
		l -= 2;
	ft_hash(list, a, d);
	putn(l, '0');
	ft_putstr(c);
}

void	ft_hex2(t_printf *list, char *c, uintmax_t d, int a)
{
	int		l;

	if (list->pres == 0)
	{
		l = list->field - ft_strlen(c);
		if ((list->flag)[4] == '#' && d != 0)
			l -= 2;
		if ((list->flag)[1] != '-' && (list->flag)[3] != '0')
		{
			putn(l, ' ');
			ft_hash(list, a, d);
			ft_putstr(c);
		}
		else if ((list->flag)[1] == '-')
		{
			ft_hash(list, a, d);
			ft_putstr(c);
			putn(l, ' ');
		}
		else if ((list->flag)[3] == '0')
			ft_hex4(list, c, d, a);
	}
	else
		ft_hex3(list, c, d, a);
}

int		ft_hex(uintmax_t d, t_printf *list, int a)
{
	int		l;
	char	*c;

	c = ft_hexx(d, a);
	if (list->pres == -1 && d == 0)
		return (ft_hex1(list));
	if (list->field == 0 || (list->field <= list->pres && list->pres != 0)
	|| (list->field < (int)ft_strlen(c) && list->pres == 0))
	{
		ft_hash(list, a, d);
		if (list->pres <= 0)
			ft_putstr(c);
		else
		{
			l = list->pres - ft_strlen(c);
			putn(l, '0');
			ft_putstr(c);
		}
	}
	else
		ft_hex2(list, c, d, a);
	free(c);
	return (ft_nx(list, ft_strlen(c), d));
}
