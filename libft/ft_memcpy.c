/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:40:55 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/25 18:40:57 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	int				count;
	unsigned char	*dest;
	unsigned char	*src;

	dest = destination;
	src = (unsigned char*)source;
	count = 0;
	while (count < (int)n)
	{
		*dest++ = *src++;
		count++;
	}
	return (destination);
}
