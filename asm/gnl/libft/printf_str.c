/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:08:23 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 16:15:02 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	strn(int l, char *s)
{
	int		i;

	i = 0;
	if (l != 0)
	{
		while (l > 0)
		{
			write(1, &s[i], 1);
			l--;
			i++;
		}
	}
	else
		ft_putstr(s);
}

void	ft_str3(int n, t_printf *list, char *s)
{
	int		l;
	int		p;

	p = list->pres;
	l = n - p;
	if ((list->flag)[1] == '-')
	{
		strn(p, s);
		if ((list->flag)[3] != '0')
			putn(l, ' ');
		else
			putn(l, '0');
	}
	else
	{
		if ((list->flag)[3] != '0')
			putn(l, ' ');
		else
			putn(l, '0');
		strn(p, s);
	}
}

void	ft_str4(t_printf *list, char *s, int l)
{
	if ((list->flag)[1] == '-')
	{
		ft_putstr(s);
		putn(l, ' ');
	}
	else
	{
		if ((list->flag)[3] != '0')
			putn(l, ' ');
		else
			putn(l, '0');
		ft_putstr(s);
	}
}

void	ft_str2(t_printf *list, char *s, int n)
{
	int		l;

	if (list->pres == 0 || list->pres > (int)ft_strlen(s))
	{
		l = n - ft_strlen(s);
		ft_str4(list, s, l);
	}
	else
		ft_str3(n, list, s);
}

int		ft_str(char *s, t_printf *list)
{
	int		n;
	int		i;

	i = 0;
	n = list->field;
	if (list->pres == -1)
	{
		ft_str0(list);
		return (list->field);
	}
	else if (s == NULL)
		s = "(null)";
	n = ft_ns(list, ft_strlen(s));
	if (list->field == 0 ||
	(list->field <= list->pres && list->pres < (int)(ft_strlen(s)))
	|| (list->field < (int)(ft_strlen(s)) && list->pres == 0))
	{
		if (list->pres == 0 || list->pres > (int)ft_strlen(s))
			strn((n = ft_strlen(s)), s);
		else
			strn((n = list->pres), s);
	}
	else
		ft_str2(list, s, n);
	return (n);
}
