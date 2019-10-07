/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:31:05 by ddodukal          #+#    #+#             */
/*   Updated: 2018/12/01 13:06:44 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (n > i)
	{
		if (((unsigned char *)s2)[i] == (unsigned char)c)
		{
			i++;
			ft_memcpy(s1, s2, i);
			return (&s1[i]);
		}
		i++;
	}
	ft_memcpy(s1, s2, i);
	return (NULL);
}
