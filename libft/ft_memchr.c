/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:07:55 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/29 14:07:56 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	int		count;
	char	b;

	b = (char)c;
	str = (char *)s;
	count = 0;
	while (count != (int)n)
	{
		if (*str == b)
			return (str);
		str++;
		count++;
	}
	return (NULL);
}
