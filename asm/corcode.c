/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corcode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:07:14 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/22 15:29:22 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		convbyte(t_asm *asem, int fd1, int fd2, int l)
{
	int		i;
	int		r;
	char	*s;

	r = 0;
	i = l;
	while (i >= 0)
	{
		read(fd1, &asem->check.convert[i], 1);
		r++;
		i--;
	}
	
	s = ft_itoa((short)asem->check.half[0]);
//	printf("%s\n", s);
	write(fd2, s, ft_strlen(s));
//	write(fd2, "test", 4);
	return (r);
}

void	ft_gettype(int n, int s[3])
{
	int		i;

	i = 2;
	n = tobin(n);
	n /= 100;
	while (i >= 0)
	{
		if (n % 100 == 1)
			s[i] = 1;
		else if (n % 100 == 10)
			s[i] = 2;
		else if (n % 100 == 11)
			s[i] = 3;
		n /= 100;
		i--;
	}
}

void	corcode(int fd1, int fd2, t_asm *asem)
{
	int				i;
	int				j;
	int				l;
	int				r;
	unsigned char	c;
	int				n[3];
	int				f;
	char			*s;

	r = 1;
	l = 0;
	f = 0;
	n[0] = 2;
	n[1] = 0;
	n[2] = 0;
	while ((r = read(fd1, &c, 1)) != 0)
	{
		n[0] = 2;
		n[1] = 0;
		n[2] = 0;
		l += r;
		j = c;
		if (c >= 11)
			j -= 10;
		else
			j += 6;
		write(fd2, asem->opers[j], strlen(asem->opers[j]));
		if (c >= 2 & c <= 8 || c == 10 || c == 11
		|| c == 13 || c == 14 || c == 16)
		{
			r = read(fd1, &c, 1);
			ft_gettype(c, n);
			l++;
		}
		i = 0;
		while (i < 3)
		{
			if (n[i] == 0)
				break ;
			if (f > 0)
				write(fd2, ",", 1);
			if (n[i] == 1)
			{
				write(fd2, " r", 2);
				r = read(fd1, &c, 1);
				l += r;
				s = ft_itoa(c);
				write(fd2, s, 1);
				f++;
			}
			if (n[i] == 2)
			{
				write(fd2, " %", 2);
				if (j == 15 || j == 0 || j == 1 || j == 4 || j == 5)
					l += convbyte(asem, fd1, fd2, 1);
				else
					l += convbyte(asem, fd1, fd2, 3);
				f++;
			}
			if (n[i] == 3)
			{
				l += convbyte(asem, fd1, fd2, 1);
				f++;
			}
			i++;
		}
		f = 0;
		write (fd2, "\n", 1);
	}
	if (l != asem->cl)
		corerr(5, asem->bn + l, asem);
}
