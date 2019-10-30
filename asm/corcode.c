/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corcode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:07:14 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/30 13:36:18 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		corarg2(t_asm *asem, int i, int j)
{
	int				l;

	l = 0;
	if (asem->n[i] == 2)
	{
		write(asem->fd2, "%", 1);
		if (j == 15 || j >= 0 & j <= 3 || j == 5)
			l += convbyte(asem, asem->fd1, asem->fd2, 1);
		else
			l += convbyte(asem, asem->fd1, asem->fd2, 3);
		asem->ln++;
	}
	if (asem->n[i] == 3)
	{
		l += convbyte(asem, asem->fd1, asem->fd2, 1);
		asem->ln++;
	}
	return (l);
}

int		corarg1(t_asm *asem, int i, int j)
{
	unsigned char	c;
	int				l;
	int				r;
	char			*s;

	l = 0;
	if (asem->n[i] == 1)
	{
		write(asem->fd2, "r", 1);
		r = read(asem->fd1, &c, 1);
		l += r;
		s = ft_itoa(c);
		write(asem->fd2, s, 1);
		free(s);
		asem->ln++;
	}
	l += corarg2(asem, i, j);
	return (l);
}

int		corargs(t_asm *asem, int j)
{
	int				i;
	int				l;

	i = 0;
	asem->ln = 0;
	l = 0;
	while (i < 3)
	{
		if (asem->n[i] == 0)
			break ;
		if (asem->ln > 0)
			write(asem->fd2, ",", 1);
		write(asem->fd2, " ", 1);
		l += corarg1(asem, i, j);
		i++;
	}
	return (l);
}

int		corcode(int fd1, int fd2, t_asm *asem)
{
	int				l;
	int				r;
	unsigned char	c;
	int				j;

	l = 0;
	asem->fd1 = fd1;
	asem->fd2 = fd2;
	while ((r = read(fd1, &c, 1)) != 0)
	{
		j = corinit(asem, c, fd2);
		if (c >= 2 & c <= 8 || c == 10 || c == 11
		|| c == 13 || c == 14 || c == 16)
		{
			r += read(fd1, &c, 1);
			ft_gettype(c, asem->n);
		}
		l += corargs(asem, j) + r;
		write(fd2, "\n", 1);
	}
	return (l);
}
