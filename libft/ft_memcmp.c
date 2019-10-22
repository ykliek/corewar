/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 20:02:12 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/04 20:02:13 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	bytecmp(unsigned char *s1, unsigned char *s2, unsigned char n)
{
	while (n)
	{
		if (*(s1++) != *(s2++))
			return ((int)(*(--s1) - *(--s2)));
		n--;
	}
	return (0);
}

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	*firstlong;
	unsigned long	*secondlong;
	size_t			m;

	if ((m = n / sizeof(long)))
	{
		firstlong = (unsigned long *)s1;
		secondlong = (unsigned long *)s2;
		while (m)
		{
			if (*(firstlong++) == *(secondlong++))
				m--;
			else
				return (bytecmp((unsigned char *)(--firstlong),
								(unsigned char *)(--secondlong), sizeof(long)));
		}
		if ((m = n % sizeof(long)))
			return (bytecmp((unsigned char *)firstlong,
							(unsigned char *)secondlong, (unsigned char)m));
		else
			return (0);
	}
	return (bytecmp((unsigned char *)s1,
					(unsigned char *)s2, (unsigned char)n));
}
