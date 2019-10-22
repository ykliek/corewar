/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 22:54:30 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/03 22:54:32 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			m;
	unsigned char	i;
	unsigned long	*temp;
	unsigned long	*end;

	if ((m = len / sizeof(long)))
	{
		temp = (unsigned long *)b;
		i = 0;
		while (i < sizeof(long))
			((unsigned char *)b)[len - 1 - i++] = (unsigned char)c;
		end = (unsigned long *)&((unsigned char *)b)[len - i];
		while (m)
			temp[(m--) - 1] = *end;
	}
	else
	{
		while (len--)
			((unsigned char *)b)[len] = (unsigned char)c;
	}
	return (b);
}
