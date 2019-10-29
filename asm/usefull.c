/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:15:54 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/22 14:17:30 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		power(int n, int p)
{
	int		a;

	a = n;
	while (p > 1)
	{
		n *= a;
		p--;
	}
	if (p <= 0)
		return (1);
	return (n);
}

int		conlen(int d, int a)
{
	int		i;

	i = 0;
	while (d > 0)
	{
		d /= a;
		i++;
	}
	return (i);
}

char	*tohex(int n)
{
	int		l;
	char	*s;

	l = conlen(n, 16);
	s = ft_memalloc(sizeof(char) * l + 1);
	s[l] = '\0';
	l--;
	while (l >= 0)
	{
		if ((n % 16) <= 9)
			s[l] = (n % 16) + '0';
		else
			s[l] = (n % 16) + 'a' - 10;
		l--;
		n /= 16;
	}
	return (s);
}

int		todec(int n)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	while (n > 0)
	{
		r += ((n % 10) * power(2, i));
		n /= 10;
		i++;
	}
	return (r);
}

int		tobin(int n)
{
	int		r;
	int		t;
	int		i;

	r = 0;
	i = -1;
	while (n > 0)
	{
		i++;
		t = n % 2;
		t *= power(10, i);
		r += t;
		n /= 2;
	}
	return (r);
}
