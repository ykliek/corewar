/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 22:56:44 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/04 22:56:45 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lenfirst;
	size_t	lensec;
	size_t	l;

	lenfirst = ft_strlen(dst);
	lensec = ft_strlen(src);
	if (lenfirst >= dstsize)
		return (dstsize + lensec);
	l = (lensec < (dstsize - lenfirst - 1)) ? lensec : (dstsize - lenfirst - 1);
	ft_memcpy(&dst[lenfirst], src, l);
	dst[lenfirst + l] = '\0';
	return (lenfirst + lensec);
}
