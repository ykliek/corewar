/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 11:09:46 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/29 11:09:48 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*str;
	int				count;

	dest = dst;
	str = (unsigned char*)src;
	count = (int)len;
	if (dest <= str || dest >= str + count)
	{
		while (count--)
			*dest++ = *str++;
	}
	else
	{
		dest += count - 1;
		str += count - 1;
		while (count--)
			*dest-- = *str--;
	}
	return (dst);
}
