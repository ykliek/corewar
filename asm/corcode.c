/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corcode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:07:14 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/19 15:43:49 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	corcode(int fd1, int fd2, t_asm *asem)
{
	int				i;
	int				j;
	int				l;
	int				r;
	unsigned char	c;
	int				n[3];
	int				f;

	r = 1;
	l = 0;
	fd2 = 0;
	f = 0;
	while ((r = read(fd1, &c, 1)) != 0)
	{
		l += r;
		j = c;
		if (c >= 11)
			j -= 10;
		else
			j += 6;
		write(fd2, asem->opers[i], strlen(asem->opers[i]));
		if (j >= 2 & j <= 8 || j == 10 || j == 11
		|| j == 13 || j == 14 || j == 16)
		{
			r = read(fd1, &c, 1);
			l += r;
			n[0] = 0;
			n[1] = 0;
			n[2] = 0;
		}
		i = 0;
		while (i < 3)
		{
			if (f > 0)
				write(fd2, ",", 1);
			if (n[i] == 0)
				break ;
			if (n[i] == 1)
			{
				write(fd2, " r", 2);
				r = read(fd1, &c, 1);
				l += r;
				write(fd2, &c, 1);
				f++;
			}
			if (n[i] == 2)
			{
				write(fd2, " \37", 2);
				if (j == 1)
					r = read(fd1, &c, 2);
				else
					r = read(fd1, &c, 4);
				l += r;
				write(fd2, &c, 1);
				f++;
			}
			if (n[i] == 3)
			{
				r = read(fd1, &c, 1);
				l += r;
				write(fd2, &c, 2);
				f++;
			}
		}
	}
	if (l != asem->cl)
		corerr(5, asem->bn + l, asem);
}
