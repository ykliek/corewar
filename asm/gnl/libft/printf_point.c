/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:06:39 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 16:16:07 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_wh(uintmax_t d, char *c, int i)
{
	while (d > 0)
	{
		if ((d % 16) < 10)
			c[i] = '0' + (d % 16);
		else
			c[i] = 'W' + (d % 16);
		i--;
		d /= 16;
	}
}

char	*ft_heh(uintmax_t d)
{
	char		*c;
	int			p;

	p = ft_numlenx(d, 16) + 2;
	c = (char*)malloc((p + 1) * sizeof(char));
	c[p--] = '\0';
	if (d != 0)
	{
		ft_wh(d, c, p);
		c[0] = '0';
		c[1] = 'x';
	}
	else
	{
		c[0] = '0';
		c[1] = 'x';
		c[2] = '0';
	}
	return (c);
}

int		ft_point3(t_printf *list, char *c)
{
	int		n;

	n = list->field;
	if ((list->flag)[1] != '-' && (list->flag)[3] != '0')
	{
		putn((list->field - ft_strlen(c)), ' ');
		ft_putstr(c);
	}
	else if ((list->flag)[1] == '-')
	{
		ft_putstr(c);
		putn((list->field - ft_strlen(c)), ' ');
	}
	else
	{
		write(1, "0x", 2);
		putn((list->field - ft_strlen(c)), '0');
		ft_putstr(&c[2]);
	}
	return (n);
}

int		ft_point2(t_printf *list)
{
	int n;

	n = list->field;
	if (list->field == 0)
		n = 2;
	putn(n - 2, ' ');
	write(1, "0x", 2);
	return (n);
}

int		ft_point(uintmax_t d, t_printf *list)
{
	int		n;
	char	*c;

	c = ft_heh(d);
	if (list->pres == -1 && d == 0)
	{
		n = ft_point2(list);
		return (n);
	}
	else if (list->field == 0 || list->field < ft_numlen(d))
	{
		n = ft_strlen(c);
		ft_putstr(c);
	}
	else
		n = ft_point3(list, c);
	free(c);
	return (n);
}
