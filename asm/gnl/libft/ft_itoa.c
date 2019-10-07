/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:42:41 by ddodukal          #+#    #+#             */
/*   Updated: 2018/11/03 13:05:18 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_minus(char *r, int n, int l)
{
	r[l + 1] = '\0';
	r[0] = '-';
	while (l > 0)
	{
		r[l] = (-1) * (n % 10) + '0';
		n = n / 10;
		l--;
	}
}

static void	ft_plus(char *r, int n, int l)
{
	r[l] = '\0';
	l--;
	while (l >= 0)
	{
		r[l] = (n % 10) + '0';
		n = n / 10;
		l--;
	}
}

char		*ft_itoa(int n)
{
	int		l;
	int		a;
	char	*r;

	a = 0;
	a = n;
	l = 0;
	while (a != 0)
	{
		a = a / 10;
		l++;
	}
	r = (char*)malloc((l + 2) * sizeof(char));
	if (r == 0)
		return (0);
	if (n > 0)
		ft_plus(r, n, l);
	if (n < 0)
		ft_minus(r, n, l);
	if (n == 0)
		r[l] = '0';
	return (r);
}
