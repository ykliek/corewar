/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:15:35 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/26 15:40:14 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	count;
	char	*s2;

	s2 = (char *)dst;
	count = len;
	while (*src && len--)
		*dst++ = *src++;
	if (len <= count)
		ft_bzero(dst, len);
	return (s2);
}
