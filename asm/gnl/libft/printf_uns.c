/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_uns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:12:21 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 16:15:05 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_unss(uintmax_t d)
{
	char	*s;
	int		i;

	i = ft_numlent(d);
	s = (char*)malloc(i + 1 * sizeof(char));
	s[i--] = '\0';
	if (d > 0)
	{
		while (d > 0)
		{
			s[i] = d % 10 + '0';
			d /= 10;
			i--;
		}
	}
	else
		s[i] = '0';
	return (s);
}

void	ft_uns21(t_printf *list, char *s, int n)
{
	int		l;
	int		p;

	p = list->pres;
	if (p > (int)ft_strlen(s))
		l = n - p;
	else
		l = n - ft_strlen(s);
	p -= ft_strlen(s);
	if ((list->flag)[1] != '-')
	{
		putn(l, ' ');
		putn(p, '0');
		ft_putstr(s);
	}
	else
	{
		putn(p, '0');
		ft_putstr(s);
		putn(l, ' ');
	}
}

void	ft_uns2(t_printf *list, char *s, int n)
{
	int		l;

	if (list->pres == 0)
	{
		l = n - ft_strlen(s);
		if ((list->flag)[1] != '-' && (list->flag)[3] != '0')
		{
			putn(l, ' ');
			ft_putstr(s);
		}
		if ((list->flag)[1] == '-')
		{
			ft_putstr(s);
			putn(l, ' ');
		}
		if ((list->flag)[3] == '0')
		{
			putn(l, '0');
			ft_putstr(s);
		}
	}
	else
		ft_uns21(list, s, n);
}

void	ft_uns3(t_printf *list, char *s, int n, uintmax_t d)
{
	int		l;

	if (list->pres == -1 && d == 0)
	{
		putn(n, ' ');
		return ;
	}
	else if (list->pres == 0 || list->pres < (int)ft_strlen(s))
		ft_putstr(s);
	else
	{
		l = list->pres - ft_strlen(s);
		putn(l, '0');
		ft_putstr(s);
	}
}

int		ft_uns(uintmax_t d, t_printf *list)
{
	int		n;
	char	*s;

	s = ft_unss(d);
	n = ft_nu(list, ft_strlen(s));
	if (list->pres == -1 && d == 0)
	{
		if (list->field != 0)
			n = list->field;
		else
			n = 0;
		putn(n, ' ');
		return (n);
	}
	if (list->field == 0 || (list->field <= list->pres && list->pres != 0)
	|| (list->field < (int)ft_strlen(s) && list->pres == 0))
		ft_uns3(list, s, n, d);
	else
		ft_uns2(list, s, n);
	free(s);
	return (n);
}
