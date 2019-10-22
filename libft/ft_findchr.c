/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:25:10 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/21 22:25:11 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrchr(const void *s, int c, size_t n)
{
	unsigned char	find;
	unsigned char	*temp;

	find = (unsigned char)c;
	temp = (unsigned char *)s + n - 1;
	while (n)
	{
		if (*temp == find)
			return (temp);
		temp--;
		n--;
	}
	return (NULL);
}

size_t		ft_findchr(const char *s, int c, size_t n, unsigned char revers)
{
	char	*result;

	if (!s)
		return (0);
	if (n)
	{
		if (revers)
			return ((result = ft_memrchr(s, c, n)) ? (result - s + 1) : 0);
		else
			return ((result = ft_memchr(s, c, n)) ? (result - s + 1) : 0);
	}
	else
	{
		if (revers)
			return ((result = ft_strrchr(s, c)) ? (result - s + 1) : 0);
		else
			return ((result = ft_strchr(s, c)) ? (result - s + 1) : 0);
	}
}
