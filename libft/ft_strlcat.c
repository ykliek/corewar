/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:57:50 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/26 16:57:51 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	count;
	size_t	count_2;

	count = 0;
	count_2 = 0;
	if (dst_size == 0)
		return (ft_strlen(src));
	while (dst[count] && count < dst_size)
		count++;
	count_2 = count;
	while (src[count - count_2] && count < dst_size - 1)
	{
		dst[count] = src[count - count_2];
		count++;
	}
	if (count_2 < dst_size)
		dst[count] = '\0';
	return (count_2 + ft_strlen(src));
}
