/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:35:13 by ddodukal          #+#    #+#             */
/*   Updated: 2018/12/01 13:03:46 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s2 < s1)
	{
		while (n)
		{
			((char*)s1)[n - 1] = ((char*)s2)[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			((char*)s1)[i] = ((char*)s2)[i];
			i++;
		}
	}
	return (s1);
}
