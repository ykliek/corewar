/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_oct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:08:14 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 16:14:51 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_oct(uintmax_t d)
{
	uintmax_t	n;
	char		*c;
	int			i;

	i = ft_numlenx(d, 8);
	c = (char*)malloc(i + 1 * sizeof(char));
	n = d;
	c[i] = '\0';
	i--;
	if (d != 0)
	{
		while (n > 0)
		{
			c[i] = '0' + (n % 8);
			i--;
			n /= 8;
		}
	}
	else
		c[i] = '0';
	return (c);
}

void	ft_octal21(t_printf *list, int n, char *c, uintmax_t d)
{
	int		l;

	l = n - ft_strlen(c);
	if ((list->flag)[4] == '#' && (list->flag)[3] != '0' && d != 0)
		l--;
	if ((list->flag)[1] != '-' && (list->flag)[3] != '0')
	{
		putn(l, ' ');
		ft_hash(list, 3, d);
		ft_putstr(c);
	}
	else if ((list->flag)[1] == '-')
	{
		ft_hash(list, 3, d);
		ft_putstr(c);
		putn(l, ' ');
	}
	else if ((list->flag)[3] == '0')
	{
		putn(l, '0');
		ft_putstr(c);
	}
}

void	ft_octal22(t_printf *list, int n, char *c, uintmax_t d)
{
	int		p;
	int		l;

	p = list->pres;
	l = ft_lo(list, n, ft_strlen(c), d);
	p -= ft_strlen(c);
	if (list->flag[4] == '#' && d != 0)
		p--;
	if ((list->flag)[1] != '-')
	{
		putn(l, ' ');
		putn(p, '0');
		ft_hash(list, 3, d);
		ft_putstr(c);
	}
	else
	{
		putn(p, '0');
		ft_hash(list, 3, d);
		ft_putstr(c);
		putn(l, ' ');
	}
}

void	ft_octal3(t_printf *list, char *c, uintmax_t d)
{
	int		l;

	if (list->pres == 0)
	{
		ft_hash(list, 3, d);
		ft_putstr(c);
	}
	else
	{
		l = list->pres - ft_strlen(c);
		if ((list->flag)[4] == '#' && d != 0)
			l -= 1;
		ft_hash(list, 3, d);
		putn(l, '0');
		ft_putstr(c);
	}
}

int		ft_octal(uintmax_t d, t_printf *list)
{
	int		n;
	char	*c;

	c = ft_oct(d);
	if (list->pres == -1 && d == 0)
		n = ft_octal1(list);
	else
	{
		n = ft_no(list, ft_strlen(c), d);
		if (list->field == 0 || (list->field <= list->pres && list->pres != 0)
		|| (list->field < (int)ft_strlen(c) && list->pres == 0))
			ft_octal3(list, c, d);
		else
		{
			if (list->pres == 0)
				ft_octal21(list, n, c, d);
			else
				ft_octal22(list, n, c, d);
		}
	}
	free(c);
	return (n);
}
