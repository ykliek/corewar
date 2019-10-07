/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:08:07 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 16:14:43 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_numm2(char c, char *s, intmax_t d, int i)
{
	if (c != '\0')
	{
		s[i] = c;
		c = '\0';
		i--;
	}
	if (d != 0)
	{
		while (d > 0)
		{
			s[i] = '0' + (d % 10);
			i--;
			d /= 10;
		}
	}
	else
		s[0] = '0';
	return (s);
}

char	*ft_numm(intmax_t d)
{
	char	*s;
	int		i;
	char	c;

	i = 0;
	c = '\0';
	if (d < -9223372036854775807)
	{
		c = '0' + (-1 * (d % 10));
		d /= 10;
		i = 1;
	}
	if (d < 0)
		d *= -1;
	i += ft_numlen(d);
	s = (char*)malloc(i + 1 * sizeof(char));
	s[i] = '\0';
	i--;
	s = ft_numm2(c, s, d, i);
	return (s);
}

void	ft_num41(t_printf *list, char *s, intmax_t d, int n)
{
	int		p;
	int		l;

	p = list->pres;
	if (p > (int)ft_strlen(s))
		l = n - p;
	else
		l = n - ft_strlen(s);
	p -= ft_strlen(s);
	if ((list->flag)[0] == '+' && d >= 0)
		l--;
	if ((list->flag)[2] == ' ' && d >= 0)
		l--;
	if (d < 0)
		l--;
	putn(l, ' ');
	if (list->flag[0] == '+' && d >= 0)
		write(1, "+", 1);
	if ((list->flag)[2] == ' ' && d >= 0)
		write(1, " ", 1);
	if (d < 0)
		write(1, "-", 1);
	putn(p, '0');
	ft_putstr(s);
}

void	ft_num42(t_printf *list, char *s, intmax_t d, int n)
{
	int		p;
	int		l;

	p = list->pres;
	if (p > (int)ft_strlen(s))
		l = n - p;
	else
		l = n - ft_strlen(s);
	p -= ft_strlen(s);
	if ((list->flag)[0] == '+' && d >= 0)
		l--;
	if ((list->flag)[2] == ' ' && d >= 0)
		l--;
	if (d < 0)
		l--;
	if (list->flag[0] == '+' && d >= 0)
		write(1, "+", 1);
	if ((list->flag)[2] == ' ' && d >= 0)
		write(1, " ", 1);
	if (d < 0)
		write(1, "-", 1);
	putn(p, '0');
	ft_putstr(s);
	putn(l, ' ');
}

int		ft_num(intmax_t d, t_printf *list)
{
	int		n;
	char	*s;

	s = ft_numm(d);
	n = ft_nd(list, ft_strlen(s), d);
	if (list->pres == -1 && d == 0)
		return (ft_num1(list));
	if (list->field == 0 || (list->field <= list->pres && list->pres != 0)
	|| (list->field < ft_numlen(d) && list->pres == 0))
		ft_num2(list, d, s);
	else
	{
		if (list->pres == 0)
			ft_num3(list, s, d, n);
		else
		{
			if ((list->flag)[1] != '-')
				ft_num41(list, s, d, n);
			else if ((list->flag)[1] == '-')
				ft_num42(list, s, d, n);
		}
	}
	free(s);
	return (n);
}
