/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corcode2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:05:19 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/30 13:36:35 by ddodukal         ###   ########.fr       */
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
	write(fd2, s, ft_strlen(s));
	free(s);
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

int		corinit(t_asm *asem, unsigned char c, int fd2)
{
	int		j;

	asem->n[0] = 2;
	asem->n[1] = 0;
	asem->n[2] = 0;
	j = c;
	if (c == 10)
		j = 3;
	else if (c == 14)
		j = 0;
	else if (c == 13)
		j = 4;
	else if (c >= 11)
		j -= 10;
	else
		j += 6;
	write(fd2, asem->opers[j], strlen(asem->opers[j]));
	return (j);
}
