/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 15:28:23 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/04 15:28:24 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			m;
	unsigned long	*tempdest;
	unsigned long	*tempsrc;
	unsigned char	*enddest;
	unsigned char	*endsrc;

	tempdest = (unsigned long *)dst;
	tempsrc = (unsigned long *)src;
	m = n / sizeof(long);
	while (m)
	{
		*(tempdest++) = *(tempsrc++);
		m--;
	}
	enddest = (unsigned char *)tempdest;
	endsrc = (unsigned char *)tempsrc;
	m = n % sizeof(long);
	while (m)
	{
		*(enddest++) = *(endsrc++);
		m--;
	}
	return (dst);
}
