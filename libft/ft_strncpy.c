/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 21:54:13 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/04 21:54:14 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	length;
	size_t	l;

	length = ft_strlen(src);
	l = (length < len) ? length : len;
	ft_memmove(dst, src, l);
	if (length < len)
	{
		while (length < len)
			dst[length++] = '\0';
	}
	return (dst);
}
