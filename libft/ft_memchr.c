/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 19:49:31 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/04 19:49:33 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	find;
	unsigned char	*temp;

	find = (unsigned char)c;
	temp = (unsigned char *)s;
	while (n)
	{
		if (*temp == find)
			return (temp);
		temp++;
		n--;
	}
	return (NULL);
}
