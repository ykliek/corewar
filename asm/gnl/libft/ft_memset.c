/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:05:55 by akhobta           #+#    #+#             */
/*   Updated: 2019/10/07 16:11:52 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void		*ft_memset(void *s, int c, size_t n)
{
	size_t			i;

	i = 0;
	if (n != 0)
	{
		while (i < n)
		{
			((unsigned char *)s)[i] = (unsigned char)c;
			i++;
		}
	}
	return (s);
}
