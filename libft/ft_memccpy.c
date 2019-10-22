/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:17:45 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/04 18:17:46 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	comp;
	unsigned char	*destination;
	unsigned char	*source;

	comp = (unsigned char)c;
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (n)
	{
		if (*source == comp)
		{
			*(destination++) = *(source++);
			return (destination);
		}
		*(destination++) = *(source++);
		n--;
	}
	return (NULL);
}
